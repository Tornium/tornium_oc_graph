#ifndef NODE_H
#define NODE_H

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
    float value;
} TerminalNode;

typedef std::unordered_map<std::string, std::variant<Node, TerminalNode>> NodeMap;

float compute_expected_value(const NodeMap &nodes, const std::string &node_name, const SuccessMap &success_map);
};

#endif
