#include "generated/crime_index.h"
#include "node.h"

extern "C" bool tornium_calculate_ev(const char *oc_name, const char **keys, const double *values, int count,
                                     double *out_ev) {
    if (oc_name == nullptr or out_ev == nullptr) {
        return false;
    }

    auto graph_it = tornium::oc::graph::crime_index.find(oc_name);
    if (graph_it == tornium::oc::graph::crime_index.cend()) {
        return false;
    }

    SuccessMap success_map;
    for (int i = 0; i < count; i++) {
        if (keys[i] == nullptr) {
            return false;
        }

        success_map[std::string(keys[i])] = static_cast<float>(values[i]);
    }

    const double ev = tornium::oc::graph::compute_expected_value(graph_it->second, "START", success_map);
    *out_ev = ev;

    return true;
}

extern "C" bool tornium_calculate_probability(const char *oc_name, const char **keys, const double *values, int count,
                                              double *out_probability) {
    if (oc_name == nullptr or out_probability == nullptr) {
        return false;
    }

    auto graph_it = tornium::oc::graph::crime_index.find(oc_name);
    if (graph_it == tornium::oc::graph::crime_index.cend()) {
        return false;
    }

    SuccessMap success_map;
    for (int i = 0; i < count; i++) {
        if (keys[i] == nullptr) {
            return false;
        }

        success_map[std::string(keys[i])] = static_cast<float>(values[i]);
    }

    const double probability = tornium::oc::graph::compute_success_probability(graph_it->second, "START", success_map);
    *out_probability = probability;

    return true;
}
