#ifndef NODE_H
#define NODE_H

#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <variant>

namespace tornium::oc::graph {
typedef std::unordered_map<std::string, float> SuccessMap;

typedef struct {
    std::function<float(const SuccessMap &)> probability;
    std::string success;
    std::string failure;
} Node;

typedef struct {
    uint32_t value;
} TerminalNode;

typedef std::unordered_map<std::string, std::variant<Node, TerminalNode>> NodeMap;

double compute_expected_value(const NodeMap &nodes, const std::string &node_name, const SuccessMap &success_map);
};  // namespace tornium::oc::graph

#endif
