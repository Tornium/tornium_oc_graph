defmodule Tornium.OC.Graph.NIF do
  @moduledoc false
  @on_load :__on_load__

  @doc false
  def __on_load__ do
    path =
      :tornium_oc_graph
      |> :code.priv_dir()
      |> :filename.join(~c"libtornium_oc_graph")

    case :erlang.load_nif(path, 0) do
      :ok -> :ok
      {:error, reason} -> raise "failed to load NIF library, reason: #{inspect(reason)}"
    end
  end

  @spec calculate_ev(oc_name :: String.t(), success_map :: %{String.t() => float()}) ::
          {:ok, float()} | {:error, term()}
  def calculate_ev(oc_name, success_map) when is_binary(oc_name) and is_map(success_map) do
    :erlang.nif_error("nif not loaded")
  end

  @spec calculate_probability(oc_name :: String.t(), success_map :: %{String.t() => float()}) :: {:ok, float()} | {:error, term()}
  def calculate_probability(oc_name, success_map) when is_binary(oc_name) and is_map(success_map) do
    :erlang.nif_error("nif not loaded")
  end
end
