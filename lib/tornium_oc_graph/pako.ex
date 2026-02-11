defmodule Tornium.OC.Graph.Pako do
  @moduledoc """
  Decoder for Mermaid's Pako encoded data.

  Based upon https://github.com/mermaid-js/mermaid-live-editor/discussions/1291
  """

  @doc """
  Decode the Pako graph from a URL.
  """
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
