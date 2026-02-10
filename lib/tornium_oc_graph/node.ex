defmodule Tornium.OC.Graph.Node do
  defstruct [:name, :edges, :start?, :decision?, :terminal?, :text, :reward]

  @type t :: %__MODULE__{
          name: binary(),
          edges: [Tornium.OC.Graph.Edge.t()] | nil,
          start?: boolean(),
          decision?: boolean(),
          terminal?: boolean(),
          text: binary(),
          reward: binary()
        }

  @spec get_next(node :: t()) :: {String.t() | nil, String.t() | nil}
  def get_next(%__MODULE__{edges: edges} = _node) when is_list(edges) do
    {
      edges |> Enum.find(fn %Tornium.OC.Graph.Edge{label: label} -> label == "Pass" end) |> Map.get(:end_node),
      edges |> Enum.find(fn %Tornium.OC.Graph.Edge{label: label} -> label == "Fail" end) |> Map.get(:end_node)
    }
  end

  def get_next(%__MODULE__{edges: edges} = _node) when is_nil(edges) do
    {nil, nil}
  end
end
