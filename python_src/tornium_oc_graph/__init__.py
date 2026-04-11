"""
Tornium OC Graph — Python bindings.

Install from GitHub::

    pip install git+https://github.com/Tornium/tornium_oc_graph.git

Usage::

    from tornium_oc_graph import TorniumOCGraph

    graph = TorniumOCGraph()
    ev = graph.calculate_ev("Honey Trap", {
        "enforcer_1": 0.75,
        "muscle_1":   0.60,
        "muscle_2":   0.80,
    })
"""

import typing

from . import _libtornium_oc_graph_py

__all__ = ["calculate_ev", "calculate_probability"]
__version__ = "0.2.0"


def calculate_ev(oc_name: str, success_map: typing.Dict[str, float]) -> float:
    keys = list(success_map.keys())
    values = list(success_map.values())

    return _libtornium_oc_graph_py.calculate_ev(oc_name, keys, values)


def calculate_probability(oc_name: str, success_map: typing.Dict[str, float]) -> float:
    keys = list(success_map.keys())
    values = list(success_map.values())

    return _libtornium_oc_graph_py.calculate_probability(oc_name, keys, values)

