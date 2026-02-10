defmodule TorniumOcGraph.MixProject do
  use Mix.Project

  def project do
    [
      app: :tornium_oc_graph,
      version: "0.1.0",
      elixir: "~> 1.18",
      start_permanent: Mix.env() == :prod,
      deps: deps(),
      compilers: compilers(),
      make_env: fn -> %{"FINE_INCLUDE_DIR" => Fine.include_dir()} end
    ]
  end

  def application do
    [
      extra_applications: [:eex, :logger]
    ]
  end

  defp deps do
    [
      {:elixir_make, "~> 0.4", runtime: false},
      {:fine, "~> 0.1", runtime: false},
      {:req, "~> 0.5"},
    ]
  end

  defp compilers do
    [:elixir_make] ++ Mix.compilers()
  end
end
