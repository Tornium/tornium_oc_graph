defmodule Tornium.Test.OC.Graph do
  use ExUnit.Case

  @oc_list %{
    "Ace in the Hole" => ["imitator_1", "hacker_1", "muscle_1", "muscle_2", "driver_1"],
    "Best of the Lot" => ["picklock_1", "muscle_1", "thief_1", "imitator_1"],
    "Bidding War" => ["bomber_1", "bomber_2", "driver_1", "robber_1", "robber_2", "robber_3"],
    "Blast from the Past" => [
      "muscle_1",
      "picklock_1",
      "picklock_2",
      "hacker_1",
      "bomber_1",
      "engineer_1"
    ],
    "Break the Bank" => ["robber_1", "muscle_1", "muscle_2", "muscle_3", "thief_1", "thief_2"],
    "Cash Me if You Can" => ["thief_1", "thief_2", "lookout_1"],
    "Clinical Precision" => ["assassin_1", "imitator_1", "cat_burglar_1", "cleaner_1"],
    "Counter Offer" => ["robber_1", "looter_1", "picklock_1", "hacker_1", "engineer_1"],
    "Crane Reaction" => [
      "muscle_1",
      "muscle_2",
      "lookout_1",
      "sniper_1",
      "engineer_1",
      "bomber_1",
      "driver_1"
    ],
    "Gaslight the Way" => [
      "imitator_1",
      "imitator_2",
      "imitator_3",
      "looter_1",
      "looter_2",
      "looter_3"
    ],
    "Gone Fission" => ["hijacker_1", "bomber_1", "engineer_1", "pickpocket_1", "imitator_1"],
    "Guardian Ángels" => ["hustler_1", "enforcer_1", "engineer_1"],
    "Honey Trap" => ["enforcer_1", "muscle_1", "muscle_2"],
    "Leave No Trace" => ["techie_1", "negotiator_1", "imitator_1"],
    "Manifest Cruelty" => ["cat_burglar_1", "reviver_1", "hacker_1", "interrogator_1"],
    "Market Forces" => ["lookout_1", "enforcer_1", "negotiator_1", "muscle_1", "arsonist_1"],
    "Mob Mentality" => ["looter_1", "looter_2", "looter_3", "looter_4"],
    "No Reserve" => ["techie_1", "engineer_1", "thief_1"],
    "Pet Project" => ["picklock_1", "muscle_1", "kidnapper_1"],
    "Smoke and Wing Mirrors" => ["imitator_1", "car_thief_1", "hustler_1", "hustler_2"],
    "Sneaky Git Grab" => ["imitator_1", "pickpocket_1", "techie_1", "hacker_1"],
    "Snow Blind" => ["muscle_1", "muscle_2", "hustler_1", "imitator_1"],
    "Stacking the Deck" => ["cat_burglar_1", "driver_1", "imitator_1", "hacker_1"],
    "Stage Fright" => [
      "lookout_1",
      "muscle_1",
      "muscle_2",
      "muscle_3",
      "enforcer_1",
      "sniper_1",
      "driver_1"
    ]
  }

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

  for {oc_name, _} <- @oc_list do
    @tag oc_name: oc_name
    test "validate NIF crime #{oc_name}", %{oc_name: oc_name} do
      success_map =
        @oc_list
        |> Map.fetch!(oc_name)
        |> Enum.map(fn oc_position -> {oc_position, :rand.uniform(100) / 100} end)
        |> Map.new()

      assert {:ok, ev} = Tornium.OC.Graph.NIF.calculate_ev(oc_name, success_map)
      assert {:ok, prob} = Tornium.OC.Graph.NIF.calculate_probability(oc_name, success_map)
      assert ev >= 0
      assert prob >= 0 and prob <= 1
    end
  end
end
