defmodule Tornium.OC.Graph do
  @moduledoc """
  OC2.0 scenario-related functionality.
  """

  @doc """
  Calculate the expected value of the OC by the map of CPRs of each position.
  """
  @spec calculate_ev(oc_name :: String.t(), success_map :: %{String.t() => 0..100}) ::
          {:ok, float()} | {:error, term()}
  def calculate_ev(oc_name, success_map) when is_binary(oc_name) and is_map(success_map) do
    success_map =
      success_map
      |> Enum.map(fn {k, v} when is_integer(v) -> {k, v / 100} end)
      |> Map.new()

    try do
      Tornium.OC.Graph.NIF.calculate_ev(oc_name, success_map)
    rescue
      _ -> {:error, nil}
    end
  end

  @doc """
  Decode the mermaid code into a list of elements.
  """
  @spec decode_code(code :: String.t(), items :: [map()]) :: [
          Tornium.OC.Graph.Node.t() | Tornium.OC.Graph.Edge.t()
        ]
  def decode_code(code, items) when is_binary(code) and is_list(items) do
    code
    |> String.split("\n")
    |> Enum.map(&String.trim_leading/1)
    |> Enum.map(fn value -> parse_value(value, items) end)
    |> Enum.reject(&is_nil/1)
  end

  @doc """
  Parse a value in the mermaid graph.

  The value to be parsed can be metadata, CSS styling of nodes/edges, nodes, or edges. Any value other
  than a node or an edge will not be parsed and will be returned as `nil`.
  """
  @spec parse_value(value :: String.t(), items :: [map()]) ::
          Tornium.OC.Graph.Node.t() | Tornium.OC.Graph.Edge.t() | nil
  def parse_value("%%" <> _value, _items) do
    # This is assumed to be a value that is a comment
    nil
  end

  def parse_value("style " <> _value, _items) do
    # This is some sort of CSS styling for each edge/node which we don't care about
    nil
  end

  def parse_value("linkStyle " <> _value, _items) do
    # This is some sort of CSS styling for each edge/node which we don't care about
    nil
  end

  def parse_value("", _items) do
    # Somehow there's sometimes empty strings from the split
    nil
  end

  def parse_value("flowchart " <> _value, _items) do
    # Some sort of metadata on the direction of the graph
    nil
  end

  def parse_value(value, items) when is_binary(value) and is_list(items) do
    # This should only be nodes or edges. If the string contains "-->", the string describes an
    # edge of the graph, otherwise it describes a node in the graph.

    if String.contains?(value, "-->") do
      parse_edge(value)
    else
      parse_node(value, items)
    end
  end

  @spec parse_node(value :: String.t(), items :: [map()]) :: Tornium.OC.Graph.Node.t()
  defp parse_node(value, items) when is_binary(value) and is_list(items) do
    split_value =
      value
      |> String.replace("\"", "")
      |> String.split(["([", ")]", "{", "}", "[", "]"])

    if String.contains?(value, "([") or String.contains?(value, "[") do
      # Since the node contains "([" (text node) or "[" (post-decision node), it is a normal
      # textual node that has no impact on the graph
      parse_textual_node(split_value, items)
    else
      # If a node does not contain "([" or "[" it is a decision node
      parse_decision_node(split_value)
    end
  end

  @spec parse_decision_node(split_value :: [String.t()]) :: Tornium.OC.Graph.Node.t()
  defp parse_decision_node([node_name, node_text, ""])
       when is_binary(node_name) and is_binary(node_text) do
    %Tornium.OC.Graph.Node{
      name: node_name,
      edges: nil,
      start?: false,
      decision?: true,
      terminal?: false,
      text: node_text,
      reward: nil
    }
  end

  @spec parse_textual_node(split_value :: [String.t()], items :: [map()]) ::
          Tornium.OC.Graph.Node.t()
  defp parse_textual_node([node_name, node_text, _remainder], items)
       when is_binary(node_name) and is_binary(node_text) and is_list(items) do
    %Tornium.OC.Graph.Node{
      name: node_name,
      edges: nil,
      start?: false,
      decision?: false,
      terminal?: String.contains?(node_text, "Rewards: "),
      text: node_text,
      reward: parse_reward(node_text, items)
    }
  end

  @spec parse_reward(node_text :: String.t(), items :: [map()]) :: non_neg_integer() | term()
  defp parse_reward(node_text, items) when is_binary(node_text) and is_list(items) do
    reward_string =
      node_text
      |> String.split(["Rewards: ~", "Rewards: "])
      |> Enum.at(1)

    case reward_string do
      nil ->
        nil

      "$" <> money_string ->
        money_string
        |> String.split(",")
        |> Enum.join("")
        |> String.to_integer()

      "Respect: " <> _ = respect_scope_money_string ->
        case String.split(respect_scope_money_string, ", ", parts: 3) do
          ["Respect: " <> _, "Scope: " <> _, "Money: " <> money_string] ->
            money_string
            |> String.split(",")
            |> Enum.join("")
            |> String.to_integer()

          ["Respect: " <> _, "Scope: " <> _, "Items: " <> item_string] ->
            item_string
            |> String.split(", ")
            |> Enum.map(fn value -> item_value(value, items) end)
            |> Enum.sum()

          ["Respect: " <> _, "Money: " <> money_string] ->
            money_string
            |> String.split(",")
            |> Enum.join("")
            |> String.to_integer()

          ["Respect: ~$" <> money_string] ->
            # This is a solution to a bug in allenone's site
            money_string
            |> String.split(",")
            |> Enum.join("")
            |> String.to_integer()
        end

      item_quantity_string ->
        # eg {"_A6S_", TerminalNode(Xanax x30)
        item_value(item_quantity_string, items)
    end
  end

  @spec item_value(item_quantity_string :: String.t() | nil, items :: [map()]) ::
          non_neg_integer()
  defp item_value(item_quantity_string, items)
       when is_binary(item_quantity_string) and is_list(items) do
    [item_name, item_quantity] = String.split(item_quantity_string, " x")
    item_quantity = String.to_integer(item_quantity)

    item_data = Enum.find(items, fn %{"name" => n} -> n == item_name end)

    case item_data do
      %{"value" => %{"market_value" => market_value}}
      when is_integer(market_value) and market_value > 0 ->
        market_value * item_quantity

      %{"value" => %{"sell_price" => sell_price}}
      when is_integer(sell_price) and sell_price > 0 ->
        sell_price * item_quantity

      _ ->
        0
    end
  end

  @spec parse_edge(value :: String.t()) :: Tornium.OC.Graph.Edge.t()
  defp parse_edge(value) when is_binary(value) do
    case String.split(value, [" -- ", " --> "]) do
      [edge_start, edge_label, edge_end] ->
        ["", edge_label, ""] = String.split(edge_label, "\"")

        %Tornium.OC.Graph.Edge{
          start_node: edge_start,
          end_node: edge_end,
          label: edge_label
        }

      [edge_start, edge_end] ->
        %Tornium.OC.Graph.Edge{
          start_node: edge_start,
          end_node: edge_end,
          label: nil
        }
    end
  end

  @spec build_graph(values :: [Tornium.OC.Graph.Node.t() | Tornium.OC.Graph.Edge.t()]) :: [
          Tornium.OC.Graph.Node.t()
        ]
  def build_graph(values) when is_list(values) do
    start_node =
      Enum.find(values, fn
        %Tornium.OC.Graph.Node{name: node_name} -> node_name == "_Prelude_"
        _ -> false
      end)

    do_build_graph(values, start_node)
  end

  defp do_build_graph(values, current_node, nodes \\ [])

  defp do_build_graph(
         values,
         %Tornium.OC.Graph.Node{name: current_node_name} = current_node,
         nodes
       )
       when is_list(values) and is_list(nodes) do
    outgoing_edges =
      Enum.filter(values, fn
        %Tornium.OC.Graph.Edge{start_node: edge_start_node} ->
          edge_start_node == current_node_name

        _ ->
          false
      end)

    current_node = %Tornium.OC.Graph.Node{
      current_node
      | terminal?: outgoing_edges == [],
        edges: outgoing_edges
    }

    Enum.reduce(
      outgoing_edges,
      [current_node | nodes],
      fn %Tornium.OC.Graph.Edge{end_node: next_node_name}, nodes_acc ->
        next_node =
          Enum.find(values, fn
            %Tornium.OC.Graph.Node{name: node_name} -> node_name == next_node_name
            _ -> false
          end)

        do_build_graph(values, next_node, nodes_acc)
      end
    )
  end

  defp do_build_graph(_values, current_node, nodes)
       when is_nil(current_node) and is_list(nodes) do
    nodes
  end

  @doc """
  Reduce a list of all nodes and edges of a graph into a minimal set of nodes and edges
  that impact the final probabilities and effective value.

  We want to remove minimized edges and nodes that have no decisions such that all remaining
  nodes are decision nodes, terminal nodes, or the starting node. We also want to update the
  edges of the nodes to be the edges between decision/terminal nodes.
  """
  @spec reduce(graph :: [Tornium.OC.Graph.Node.t()]) :: [Tornium.OC.Graph.Node.t()]
  def reduce(graph) when is_list(graph) do
    "_Prelude_"
    |> jump_to_meaningful(graph, %{})
    |> then(fn {%Tornium.OC.Graph.Node{} = node, _acc} ->
      %Tornium.OC.Graph.Node{node | start?: true}
    end)
    |> traverse_and_reduce(graph)
    |> Map.values()
  end

  @spec traverse_and_reduce(
          current_node :: Tornium.OC.Graph.Node.t() | nil,
          graph :: [Tornium.OC.Graph.Node.t()],
          acc :: %{String.t() => Tornium.OC.Graph.Node.t()}
        ) :: %{String.t() => Tornium.OC.Graph.Node.t()}
  defp traverse_and_reduce(current_node, graph, acc \\ %{})

  defp traverse_and_reduce(
         %Tornium.OC.Graph.Node{name: current_node_name} = current_node,
         graph,
         acc
       )
       when is_list(graph) and is_map(acc) do
    if Map.has_key?(acc, current_node_name) do
      acc
    else
      do_traverse(current_node, graph, acc)
    end
  end

  defp traverse_and_reduce(current_node, _graph, acc) when is_nil(current_node) and is_map(acc) do
    acc
  end

  defp do_traverse(
         %Tornium.OC.Graph.Node{name: current_node_name, edges: edges} = current_node,
         graph,
         acc
       ) do
    # Only keep edges to decision/terminal nodes
    relevant_edges =
      Enum.map(edges, fn %Tornium.OC.Graph.Edge{} = edge ->
        {final_node, _acc} = jump_to_meaningful(edge.end_node, graph, acc)
        %Tornium.OC.Graph.Edge{edge | end_node: final_node.name}
      end)

    current_node = %Tornium.OC.Graph.Node{current_node | edges: relevant_edges}
    acc = Map.put(acc, current_node_name, current_node)

    Enum.reduce(relevant_edges, acc, fn %Tornium.OC.Graph.Edge{end_node: next_node_name}, acc ->
      graph
      |> Enum.find(fn %Tornium.OC.Graph.Node{name: node_name} -> node_name == next_node_name end)
      |> do_traverse(graph, acc)
    end)
  end

  defp jump_to_meaningful(current_node_name, graph, acc) do
    current_node =
      Enum.find(graph, fn %Tornium.OC.Graph.Node{name: node_name} ->
        current_node_name == node_name
      end)

    case current_node do
      nil ->
        {nil, acc}

      %Tornium.OC.Graph.Node{decision?: true} = node ->
        {node, acc}

      %Tornium.OC.Graph.Node{edges: [], terminal?: true} = node ->
        {node, acc}

      %Tornium.OC.Graph.Node{edges: [%Tornium.OC.Graph.Edge{end_node: next_node}]} ->
        # Only one outgoing edge, continue jumping
        jump_to_meaningful(next_node, graph, acc)

      %Tornium.OC.Graph.Node{edges: edges, decision?: false} = _node when is_list(edges) ->
        # There are multiple outgoing edges from a non-decision. We want to check if the edges
        # are going to converge upon a non-decision node such that we can minimize it into one
        # edge.

        target_nodes =
          Enum.map(edges, fn %Tornium.OC.Graph.Edge{end_node: next_node} ->
            jump_to_meaningful(next_node, graph, acc)
          end)

        unique_target_node_names =
          target_nodes
          |> Enum.map(fn {node, _acc} -> node && node.name end)
          |> Enum.uniq()

        case unique_target_node_names do
          [_single_target_node] ->
            # All parallel edges converge to the same meaningful node
            {target_node, _} = List.first(target_nodes)
            {target_node, acc}

          _ ->
            # Edges diverge to different meaningful nodes; cannot reduce further.
            # Return the current non-decision node as-is.
            {current_node, acc}
        end
    end
  end
end
