# Tornium OC Graph
OC scenario graphs as generated C++ code

Credit to [Allenone](https://www.torn.com/profiles.php?XID=2033011) for the original research into OC scenarios and for creating the [original
graphs for OC scenarios](https://www.torn.com/forums.php#/p=threads&f=67&t=16458267).

## Supported Languages
- Elixir
- C++
- Python

Other languages that are not directly supported by the library can be made to work by linking the
shared object generated when compiling this library to your application (depending on how your
language's FFI works).

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
