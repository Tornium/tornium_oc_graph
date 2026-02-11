#include <erl_nif.h>

#include <fine.hpp>
#include <map>
#include <optional>
#include <string>

#include "generated/crime_index.h"
#include "node.h"

using namespace tornium::oc::graph;

std::variant<fine::Ok<double>, fine::Error<std::nullopt_t>> calculate_ev(
    ErlNifEnv* /* env */, const std::string oc_name, const std::map<std::string, double> success_map) {
    auto graph_it = tornium::oc::graph::crime_index.find(oc_name);

    if (graph_it == tornium::oc::graph::crime_index.cend()) {
        return fine::Error<std::nullopt_t>(std::nullopt);
    }

    const double ev = tornium::oc::graph::compute_expected_value(graph_it->second, "START",
                                                                 SuccessMap{success_map.cbegin(), success_map.cend()});

    return fine::Ok<double>(ev);
}
FINE_NIF(calculate_ev, 0);

FINE_INIT("Elixir.Tornium.OC.Graph.NIF");
