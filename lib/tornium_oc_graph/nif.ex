defmodule Tornium.OC.Graph.NIF do
  @moduledoc false
  @on_load :__on_load__

  @doc false
  def __on_load__ do
    path = :filename.join(:code.priv_dir(Tornium.OC.Graph), ~c"libtornium_oc_graph_ex")

    case :erlang.load_nif(path, 0) do
      :ok -> :ok
      {:error, reason} -> raise "failed to load NIF library, reason: #{inspect(reason)}"
    end
  end
end
