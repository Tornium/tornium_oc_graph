defmodule Tornium.OC.Graph.Edge do
  defstruct [:start_node, :end_node, :label]

  @typedoc """
  The label on an edge between two nodes. If a label exists, the label should either be
  "Fail" or "Pass" indicating the direction of the decision. If the label does not exist,
  that indicates that the start node is not a decision node where the path splits.
  """
  @type edge_label :: String.t() | nil

  @type t :: %__MODULE__{
    start_node: String.t(),
    end_node: String.t(),
    label: edge_label()
  }
end
