defmodule Tornium.Test.OC.Graph do
  use ExUnit.Case

  test "validate NIF" do
    assert {:error, nil} = Tornium.OC.Graph.NIF.calculate_ev("foo", %{})

    assert {:ok, ev} =
             Tornium.OC.Graph.NIF.calculate_ev("Honey Trap", %{
               "enforcer_1" => 0.0,
               "muscle_1" => 0.0,
               "muscle_2" => 0.0
             })

    assert Float.floor(ev) == 0
  end
end
