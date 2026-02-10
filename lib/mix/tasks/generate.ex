defmodule Mix.Tasks.Tornium.Oc.Graph.Generate do
  @moduledoc """
  Generate the C++ files for each OC graph from [Allenone's scenario graphs](https://www.torn.com/forums.php#/p=threads&f=67&t=16458267&b=0&a=0).
  """

  use Mix.Task

  @doc false
  @impl true
  def run(_argv) do
    {:ok, _} = Application.ensure_all_started(:req)

    Tornium.OC.Graph.Data.data_uris()
    |> Enum.reject(fn {_oc_name, uri} -> is_nil(uri) end)
    |> Enum.each(fn {oc_name, oc_uri} ->
      oc_uri
      |> Tornium.OC.Graph.Pako.decode_pako()
      |> Map.fetch!("code")
      |> Tornium.OC.Graph.decode_code()
      |> Tornium.OC.Graph.build_graph()
      |> Tornium.OC.Graph.reduce()
      # |> IO.inspect(label: oc_name, limit: :infinity)
      |> Tornium.OC.Graph.Generator.generate_cpp(oc_name)
    end)
  end
end
