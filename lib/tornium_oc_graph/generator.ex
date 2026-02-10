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
    #ifndef <%= oc_name |> String.upcase() %>
    #define <%= oc_name |> String.upcase() %>

    #include "node.h"

    using namespace tornium::oc::graph;

    static const NodeMap <%= oc_name %> {
    <%= graph |> Enum.map(&render_node/1) |> Enum.join(",\n") %>
    };
    #endif
    """
  end

  @spec render_node(node :: Tornium.OC.Graph.Node.t()) :: String.t()
  def render_node(%Tornium.OC.Graph.Node{start?: true} = node) do
    {success_node, failure_node} = Tornium.OC.Graph.Node.get_next(node)

    # TODO: handle inner of successmap lambda
    ~e"{\"START\", Node([](const SuccessMap &m){ }, \"<%= success_node %>\", \"<%= failure_node %>\")}"
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
    ~e"{\"<%= node_name %>\", TerminalNode(<%= reward %>)"
  end

  def render_node(%Tornium.OC.Graph.Node{name: node_name, decision?: true} = node) do
    {success_node, failure_node} = Tornium.OC.Graph.Node.get_next(node)

    # TODO: handle inner of successmap lambda
    ~e"{\"<%= node_name %>\", Node([](const SuccessMap &m){ }, \"<%= success_node %>\", \"<%= failure_node %>\")}"
  end

  # This is a temporary resolution for invalid nodes with outgoing edges that merge before a decision node but are considered a decision node.
  def render_node(%Tornium.OC.Graph.Node{start?: false, terminal?: false, decision?: false}),
    do: ""
end
