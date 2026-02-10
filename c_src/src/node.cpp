#include "node.h"

#include <string>
#include <variant>

using namespace tornium::oc::graph;

float compute_expected_value(const NodeMap &nodes, const std::string &node_name, const SuccessMap &success_map) {
    const auto &variant_node = nodes.at(node_name);

    if (std::holds_alternative<TerminalNode>(variant_node)) {
        return std::get<TerminalNode>(variant_node).value;
    }

    const Node &node = std::get<Node>(variant_node);
    const float probablity = node.probability(success_map);

    return probablity * tornium::oc::graph::compute_expected_value(nodes, node.success, success_map) +
           (1 - probablity) * tornium::oc::graph::compute_expected_value(nodes, node.failure, success_map);
}
