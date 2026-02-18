#include "node.h"

#include <string>
#include <variant>

using namespace tornium::oc::graph;

double tornium::oc::graph::compute_expected_value(const NodeMap &nodes, const std::string &node_name,
                                                  const SuccessMap &success_map) {
    const auto &variant_node = nodes.at(node_name);

    if (std::holds_alternative<TerminalNode>(variant_node)) {
        return std::get<TerminalNode>(variant_node).value;
    }

    const Node &node = std::get<Node>(variant_node);
    const double probablity = node.probability(success_map);

    return probablity * tornium::oc::graph::compute_expected_value(nodes, node.success, success_map) +
           (1 - probablity) * tornium::oc::graph::compute_expected_value(nodes, node.failure, success_map);
}

double tornium::oc::graph::compute_success_probability(const NodeMap &nodes, const std::string &node_name,
                                                       const SuccessMap &success_map) {
    const auto &variant_node = nodes.at(node_name);

    if (std::holds_alternative<TerminalNode>(variant_node)) {
        // Terminal node with non-zero value is a success (probability = 1)
        // Terminal node with zero value is a failure (probability = 0)
        return std::get<TerminalNode>(variant_node).value != 0 ? 1.0 : 0.0;
    }

    const Node &node = std::get<Node>(variant_node);
    const double probability = node.probability(success_map);

    return probability * tornium::oc::graph::compute_success_probability(nodes, node.success, success_map) +
           (1 - probability) * tornium::oc::graph::compute_success_probability(nodes, node.failure, success_map);
}
