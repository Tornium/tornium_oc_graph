#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include <vector>
#include "abi.h"

// Helper function to extract Python lists and call the target C function
static PyObject* invoke_tornium_func(PyObject* args, 
                                     bool (*func)(const char*, const char**, const double*, int, double*)) {
    const char* oc_name;
    PyObject *keys_obj, *values_obj;

    // "sOO" expects: a string, and two generic Python Objects (our lists/tuples)
    if (!PyArg_ParseTuple(args, "sOO", &oc_name, &keys_obj, &values_obj)) {
        return NULL; // PyArg_ParseTuple raises the appropriate TypeError automatically
    }

    // PySequence_Fast safely converts lists/tuples into a flat array of borrowed references
    PyObject* keys_seq = PySequence_Fast(keys_obj, "keys must be an iterable of strings");
    PyObject* values_seq = PySequence_Fast(values_obj, "values must be an iterable of numbers");

    if (!keys_seq || !values_seq) {
        Py_XDECREF(keys_seq);
        Py_XDECREF(values_seq);
        return NULL;
    }

    Py_ssize_t count = PySequence_Fast_GET_SIZE(keys_seq);
    if (count != PySequence_Fast_GET_SIZE(values_seq)) {
        PyErr_SetString(PyExc_ValueError, "keys and values lists must have the exact same length");
        Py_DECREF(keys_seq);
        Py_DECREF(values_seq);
        return NULL;
    }

    std::vector<const char*> keys_c(count);
    std::vector<double> values_c(count);

    // Extract raw pointers and primitives
    for (Py_ssize_t i = 0; i < count; ++i) {
        PyObject* key_item = PySequence_Fast_GET_ITEM(keys_seq, i);
        PyObject* val_item = PySequence_Fast_GET_ITEM(values_seq, i);

        // Check and extract string
        if (!PyUnicode_Check(key_item)) {
            PyErr_SetString(PyExc_TypeError, "All keys must be strings");
            Py_DECREF(keys_seq);
            Py_DECREF(values_seq);
            return NULL;
        }
        // PyUnicode_AsUTF8 returns a pointer managed by Python; safe until we DECREF keys_seq
        keys_c[i] = PyUnicode_AsUTF8(key_item);

        // Check and extract float/int
        if (PyFloat_Check(val_item)) {
            values_c[i] = PyFloat_AsDouble(val_item);
        } else if (PyLong_Check(val_item)) {
            values_c[i] = (double)PyLong_AsLong(val_item);
        } else {
            PyErr_SetString(PyExc_TypeError, "All values must be numbers (float or int)");
            Py_DECREF(keys_seq);
            Py_DECREF(values_seq);
            return NULL;
        }
    }

    // Execute the underlying C ABI function
    double result = 0.0;
    bool success = func(oc_name, keys_c.data(), values_c.data(), (int)count, &result);

    // Free Python sequence references
    Py_DECREF(keys_seq);
    Py_DECREF(values_seq);

    if (!success) {
        PyErr_SetString(PyExc_RuntimeError, "Tornium calculation failed: Invalid input or missing graph name.");
        return NULL;
    }

    // Convert result back to Python Float
    return PyFloat_FromDouble(result);
}

static PyObject* py_calculate_ev(PyObject* self, PyObject* args) {
    return invoke_tornium_func(args, tornium_calculate_ev);
}

static PyObject* py_calculate_probability(PyObject* self, PyObject* args) {
    return invoke_tornium_func(args, tornium_calculate_probability);
}

static PyMethodDef TorniumMethods[] = {
    {"calculate_ev", py_calculate_ev, METH_VARARGS, "Calculate EV for a given OC graph."},
    {"calculate_probability", py_calculate_probability, METH_VARARGS, "Calculate probability for a given OC graph."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef tornium_module = {
    PyModuleDef_HEAD_INIT,
    "_libtornium_oc_graph_py",  // Name of the module
    "Python C API interface for Tornium ABI",
    -1,
    TorniumMethods
};

// Module Initialization entry point (Must match module name: PyInit_<module_name>)
PyMODINIT_FUNC PyInit__libtornium_oc_graph_py(void) {
    return PyModule_Create(&tornium_module);
}
