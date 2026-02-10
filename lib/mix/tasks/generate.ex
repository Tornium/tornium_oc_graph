defmodule Mix.Tasks.Tornium.Oc.Graph.Generate do
  @moduledoc """
  Generate the C++ files for each OC graph from [Allenone's scenario graphs](https://www.torn.com/forums.php#/p=threads&f=67&t=16458267&b=0&a=0).
  """

  use Mix.Task
  import Tornium.OC.Graph.Generator

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
      |> Tornium.OC.Graph.Generator.generate_cpp(oc_name)
    end)

    rendered_index =
      Tornium.OC.Graph.Data.data_uris()
      |> Enum.reject(fn {_oc_name, uri} -> is_nil(uri) end)
      |> Map.new()
      |> Map.keys()
      |> generate_index()

    File.write!("c_src/src/generated/crime_index.h", rendered_index)
  end

  defp generate_index(crime_names) when is_list(crime_names) do
    ~e"""
    #ifndef CRIME_INDEX_H
    #define CRIME_INDEX_H

    #include "node.h"

    <%= for crime_name <- crime_names do %>#include "generated/<%= crime_name |> String.split(" ") |> Enum.map(&String.downcase/1) |> Enum.join("_") %>.h"
    <% end %>

    namespace tornium::oc::graph {
    inline const std::unordered_map<std::string, NodeMap> crime_index = {
    <%= for crime_name <- crime_names do %>{"<%= crime_name %>", <%= crime_name |> String.split(" ") |> Enum.map(&String.downcase/1) |> Enum.join("_") %>},
    <% end %>};
    };
    #endif
    """
  end
end
