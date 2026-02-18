defmodule Tornium.OC.Graph.Node do
  defstruct [:name, :edges, :start?, :decision?, :terminal?, :text, :reward]

  @type t :: %__MODULE__{
          name: String.t(),
          edges: [Tornium.OC.Graph.Edge.t()] | nil,
          start?: boolean(),
          decision?: boolean(),
          terminal?: boolean(),
          text: String.t(),
          reward: pos_integer() | nil
        }

  @position_types [
    "Muscle",
    "Hacker",
    "Imitator",
    "Lookout",
    "Pickpocket",
    "Hustler",
    "Sniper",
    "Impersonator",
    "Engineer",
    "Robber",
    "Picklock",
    "Thief",
    "Bomber",
    "Enforcer",
    "Looter",
    "Cat Burglar",
    "Cleaner",
    "Assassin",
    "Hijacker",
    "Driver",
    "Techie",
    "Negotiator",
    "Reviver",
    "Interrogator",
    "Arsonist",
    "Kidnapper"
  ]

  @spec get_next(node :: t()) :: {String.t() | nil, String.t() | nil}
  def get_next(%__MODULE__{edges: edges} = _node) when is_list(edges) do
    {
      edges
      |> Enum.find(fn %Tornium.OC.Graph.Edge{label: label} -> label == "Pass" end)
      |> Map.get(:end_node),
      edges
      |> Enum.find(fn %Tornium.OC.Graph.Edge{label: label} -> label == "Fail" end)
      |> Map.get(:end_node)
    }
  end

  def get_next(%__MODULE__{edges: edges} = _node) when is_nil(edges) do
    {nil, nil}
  end

  @spec get_positions(node :: t()) :: [{String.t(), pos_integer()}]
  def get_positions(%__MODULE__{text: node_text} = _node) do
    escaped =
      @position_types
      |> Enum.map(&String.downcase/1)
      |> Enum.map(&Regex.escape/1)
      |> Enum.join("|")

    ~r/\b(#{escaped})(?:\s+#?\d+)?\b/
    |> Regex.scan(node_text |> String.downcase())
    |> Enum.map(&hd/1)
    |> Enum.map(&map_position/1)
    |> Enum.map(&fix_position/1)
  end

  @spec map_position(position :: String.t()) ::
          {position_name :: String.t(), position_index :: pos_integer()}
  defp map_position(position) when is_binary(position) do
    case Regex.scan(~r/^(.*?)(?:\s*#?\s*(\d+))?$/, position) do
      [[_, position_name, "#" <> position_index]] ->
        {position_name, String.to_integer(position_index)}

      [[_, position_name, position_index]] ->
        {position_name, String.to_integer(position_index)}

      [[_, position_name]] ->
        {position_name, 1}
    end
  end

  @spec fix_position({position_name :: String.t(), position_index :: pos_integer()}) :: {position_name :: String.t(), position_index :: pos_integer()}
  defp fix_position({"impersonator" = _position_name, position_index}) when is_integer(position_index) do
    # This is a bug in the upstream data. Torn uses "imitator" here.
    {"imitator", position_index}
  end

  defp fix_position({position_name, position_index}) when is_binary(position_name) and is_integer(position_index) do
    {position_name, position_index}
  end
end
