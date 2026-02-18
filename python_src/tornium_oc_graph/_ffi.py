"""
Python FFI bindings for the Tornium OC graph library.
"""

import ctypes
import ctypes.util
import os
import pathlib
import typing


def _find_library() -> str:
    """
    Attempt to locate `libtornium_oc_graph_py.so` automatically.
    """

    env = os.environ.get("TORNIUM_OC_GRAPH_LIB")
    if env and os.path.isfile(env):
        return env

    here = pathlib.Path(__file__).resolve().parent
    print(here)
    for candidate in (
        here / "libtornium_oc_graph_py.so",
        here / ".." / ".."  / "priv" / "libtornium_oc_graph_py.so",
        here / ".." / ".." / "build" / "bindings" / "python" / "libtornium_oc_graph_py.so",
    ):
        if candidate.is_file():
            return str(candidate)

    found = ctypes.util.find_library("libtornium_oc_graph_py")
    if found:
        return found

    raise FileNotFoundError(
        "Could not locate libtornium_oc_graph_py.so. "
        "Set the TORNIUM_OC_GRAPH_LIB environment variable to the full path, "
        "or place the shared library next to this Python file."
    )


_lib = ctypes.CDLL(_find_library())


def calculate_ev(oc_name: str, success_map: typing.Dict[str, float]):
    count = len(success_map)
    keys_arr = (ctypes.c_char_p * count)()
    vals_arr = (ctypes.c_double * count)()

    for i, (k, v) in enumerate(success_map.items()):
        keys_arr[i] = k.encode("utf-8")
        vals_arr[i] = v

    out_ev = ctypes.c_double(0.0)
    rc = _lib.tornium_calculate_ev(
        oc_name.encode("utf-8"),
        keys_arr,
        vals_arr,
        ctypes.c_int(count),
        ctypes.byref(out_ev),
    )

    if not rc:
        raise KeyError(f"Unknown OC scenario: {oc_name!r}")

    return out_ev.value


if __name__ == "__main__":
    ev = calculate_ev(
        "Honey Trap",
        {
            "enforcer_1": 0.5,
            "muscle_1": 0.5,
            "muscle_2": 0.5,
        },
    )
    print(f"EV for Honey Trap (all 0.5): {ev}")
