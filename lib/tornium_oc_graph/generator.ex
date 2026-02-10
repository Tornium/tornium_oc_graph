defmodule Tornium.OC.Graph.Generator do
  @moduledoc """
  C++ code generator for OC graphs.
  """

  defmacro sigil_e({:<<>>, _meta, [expr]}, []) do
    EEx.compile_string(expr, [])
  end

  def generate_cpp(graph, oc_name) do
    underscore_oc_name =
      oc_name
      |> String.split(" ")
      |> Enum.map(&String.downcase/1)
      |> Enum.join("_")

    rendered = render_template(graph, underscore_oc_name)

    File.write!("c_src/src/generated/#{underscore_oc_name}.h", rendered)
  end

  @spec render_template(graph :: [Tornium.OC.Graph.Node.t()], oc_name :: String.t()) :: String.t()
  def render_template(graph, oc_name) when is_list(graph) and is_binary(oc_name) do
    ~e"""
    #ifndef <%= oc_name |> String.upcase() %>_H
    #define <%= oc_name |> String.upcase() %>_H

    #include "node.h"

    using namespace tornium::oc::graph;

    namespace tornium::oc::graph {
    inline const NodeMap <%= oc_name %> {
    <%= graph |> Enum.map(&render_node/1) |> Enum.reject(& &1 == "") |> Enum.join(",\n") %>
    };
    };
    #endif
    """
  end

  @spec render_node(node :: Tornium.OC.Graph.Node.t()) :: String.t()
  def render_node(%Tornium.OC.Graph.Node{start?: true} = node) do
    {success_node, failure_node} = Tornium.OC.Graph.Node.get_next(node)

    ~e"{\"START\", Node([](const SuccessMap &m){ <%= node |> Tornium.OC.Graph.Node.get_positions() |> render_success_calculation() %> }, \"<%= success_node %>\", \"<%= failure_node %>\")}"
  end

  def render_node(%Tornium.OC.Graph.Node{
        name: node_name,
        edges: [],
        terminal?: true,
        reward: reward
      })
      when is_nil(reward) do
    ~e"{\"<%= node_name %>\", TerminalNode(0)}"
  end

  def render_node(%Tornium.OC.Graph.Node{
        name: node_name,
        edges: [],
        terminal?: true,
        reward: reward
      }) do
    ~e"{\"<%= node_name %>\", TerminalNode(<%= reward %>)}"
  end

  def render_node(%Tornium.OC.Graph.Node{name: node_name, decision?: true} = node) do
    {success_node, failure_node} = Tornium.OC.Graph.Node.get_next(node)

    ~e"{\"<%= node_name %>\", Node([](const SuccessMap &m){ <%= node |> Tornium.OC.Graph.Node.get_positions() |> render_success_calculation() %> }, \"<%= success_node %>\", \"<%= failure_node %>\")}"
  end

  # This is a temporary resolution for invalid nodes with outgoing edges that merge before a decision node but are considered a decision node.
  def render_node(%Tornium.OC.Graph.Node{start?: false, terminal?: false, decision?: false}) do
    ""
  end

  @spec render_success_calculation(positions :: [{String.t(), pos_integer()}]) :: String.t()
  defp render_success_calculation([{position_name, position_index}] = _positions)
       when is_binary(position_name) and is_integer(position_index) do
    "return m.at(\"#{position_name}_#{position_index}\");"
  end

  defp render_success_calculation(positions) when is_list(positions) and positions != [] do
    inner =
      positions
      |> Enum.map(fn {n, i} -> "m.at(\"#{n}_#{i}\")" end)
      |> Enum.join(" + ")

    ~e"return (<%= inner %>)/<%= length(positions) %>;"
  end

  defp render_success_calculation([] = _positions) do
    "static_assert(false, \"Missing data: This needs to be manually entered\");"
  end
end
