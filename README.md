# Tornium OC Graph
OC scenario graphs as generated C++ code.

> [!IMPORTANT]
> This library was implemented by reversing Allenone's public OC graphs, generating C++ code from those
> graphs, and patching those generated files to resolve issues in Allenone's graphs. Therefore, there may be
> certain issues that were not caught or outdated data in the generated files.

If you need help using this library or encounter any bugs, please create a ticket on [Tornium's Discord server](https://discord.gg/pPcqTRTRyF).

Credit to [Allenone](https://www.torn.com/profiles.php?XID=2033011) for the original research into OC scenarios and for creating the [original
graphs for OC scenarios](https://www.torn.com/forums.php#/p=threads&f=67&t=16458267).

## Supported Languages
- Elixir
- C++
- Python


## Installation: Elixir
For installing for Elixir, the library can be installed through GitHub by adding `tornium_oc_graph`
to your list of dependencies in `mix.exs`:

```elixir
def deps do
  [
    {:tornium_oc_graph, github: "Tornium/tornium_oc_graph"}
  ]
end
```

Documentation can be generated with [ExDoc](https://github.com/elixir-lang/ex_doc) and published on [HexDocs](https://hexdocs.pm).

## Installation: Python
For installing for Python, the library can be installed through GitHub by installing the library
through git:

```bash
pip install git+https://github.com/Tornium/tornium_oc_graph.git
```

## Installation: Other Languages
Other languages that are not directly supported by the library can be made to work by linking the
shared object generated when compiling this library to your application (depending on how your
language's FFI works). This is not a supported use-case though.

## Usage: Elixir
Once the library is installed, you can use `Tornium.OC.graph.calculate_ev/2` and  `Tornium.OC.graph.calculate_probability/2` against a set of users' CPRs to calculate the expected probability and value of the OC.

```elixir
Tornium.OC.Graph.calculate_ev("Leave No Trace", %{"imitator_1" => 87, "negotiator_1" => 87, "techie_1" => 87})
Tornium.OC.Graph.calculate_probability("Leave No Trace", %{"imitator_1" => 87, "negotiator_1" => 87, "techie_1" => 87})
```

## Usage: Python
Once the library is installed, you can use `tornium_oc_graph.calculate_ev` and `tornium_oc_graph.calculate_probability` against a setof users' CPR to calculate the expected probability and value of the OC.

```python
tornium_oc_graph.calculate_ev("Leave No Trace", {"imitator_1": 0.87, "negotiator_1": 0.87, "techie_1": 0.87})
tornium_oc_graph.calculate_probability("Leave No Trace", {"imitator_1": 0.87, "negotiator_1": 0.87, "techie_1": 0.87})
```

For a more comprehensive example, see [this function](https://github.com/Tornium/tornium/blob/a86ff285cc2f98ba07d72f5a4ae4b92de5620ec5/commons/tornium_commons/models/organized_crime.py#L83-L94) in Tornium.

## License
This library is licensed under the [Apache v2 license](LICENSE.md).
