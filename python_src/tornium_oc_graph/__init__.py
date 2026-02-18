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

from tornium_oc_graph._ffi import calculate_ev

__all__ = ["calculate_ev"]
__version__ = "0.1.0"
