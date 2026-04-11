defmodule Tornium.OC.Graph.Data do
  @moduledoc false

  @thread_id 16_458_267

  @doc false
  @spec data_uris() :: %{String.t() => String.t() | nil}
  def data_uris() do
    @thread_id
    |> get_forum_thread()
    |> map_crime_graph_urls()
  end

  @doc false
  defp get_forum_thread(thread_id) when is_integer(thread_id) do
    api_key =
      System.get_env("TORN_API_KEY") ||
        raise "The \"TORN_API_KEY\" environment variable is required"

    "https://api.torn.com/v2/forum/#{thread_id}/thread?key=#{api_key}"
    |> Req.get!()
    |> Map.get(:body)
    |> Map.get("thread")
  end

  @doc false
  defp map_crime_graph_urls(%{"content_raw" => thread_body} = _thread_data) do
    thread_body
    |> Floki.parse_document!()
    |> Floki.find("a")
    |> Enum.map(fn
      {"a", [{"href", "https://tinyurl.com/" <> _ = url}], [text_content]} ->
        {
          text_content
          |> String.split("(", trim: true)
          |> Enum.at(0)
          |> String.trim(),
          get_redirect(url)
        }

      {"a", _, _} ->
        nil
    end)
    |> Enum.reject(fn
      nil -> true
      {_, nil} -> true
      _ -> false
    end)
    |> Map.new()
  end

  @spec get_redirect(uri :: String.t()) :: String.t() | nil
  defp get_redirect(uri) when is_binary(uri) do
    redirect_uris =
      uri
      |> Req.get!(redirect: false)
      |> Map.get(:headers)
      |> Map.get("location")

    case redirect_uris do
      ["https://mermaid.live" <> _ = redirect_uri] ->
        redirect_uri

      _ ->
        nil
    end
  end
end
