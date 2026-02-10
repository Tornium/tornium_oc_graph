defmodule Tornium.OC.Graph.Pako do
  @moduledoc """
  Decode for Mermaid's Pako encoded data
  """

  # TODO: Determine return type
  # TODO: Add docs
  @spec decode_pako(link :: URI.t() | String.t()) :: %{String.t() => String.t()}
  def decode_pako(link) when is_binary(link) do
    link
    |> URI.parse()
    |> decode_pako()
  end

  def decode_pako(%URI{fragment: "pako:" <> uri_fragment}) do
    uri_fragment
    |> String.replace("-", "+")
    |> String.replace("_", "/")
    |> Base.decode64!(ignore: :whitespace, padding: false)
    |> :zlib.uncompress()
    |> Jason.decode!()
  end
end
