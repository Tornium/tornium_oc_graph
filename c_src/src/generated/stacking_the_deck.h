#ifndef STACKING_THE_DECK_H
#define STACKING_THE_DECK_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap stacking_the_deck{
    {"_A1F_", TerminalNode(0)},
    {"START", Node([](const SuccessMap &m) { return m.at("cat burglar_1"); }, "_A2_C1_", "_A1_C2_")},
    {"_A1_C2_",
     Node([](const SuccessMap &m) { return (m.at("cat burglar_1") + m.at("imitator_1")) / 2; }, "_A2_C1_", "_A1F_")},
    {"_A2_C1_", Node([](const SuccessMap &m) { return m.at("driver_1"); }, "_A3_C1_", "_A2_C2_")},
    {"_A2_C2_", Node([](const SuccessMap &m) { return m.at("driver_1"); }, "_A3_C1_", "_B1_C1_")},
    {"_A3_C1_", Node([](const SuccessMap &m) { return m.at("cat burglar_1"); }, "_A4_C1_", "_B1_C1_")},
    {"_A4_C1_", Node([](const SuccessMap &m) { return m.at("hacker_1"); }, "_A5_C1_", "_B2_C1_")},
    {"_A5F_", TerminalNode(0)},
    {"_A5_C1_", Node([](const SuccessMap &m) { return m.at("hacker_1"); }, "_A6_C1_", "_A5_C2_")},
    {"_A5_C2_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_A6S_", "_A5F_")},
    {"_A6S_", TerminalNode(0)},
    {"_A6_C1_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_A7S_", "_A6S_")},
    {"_A7S_", TerminalNode(0)},
    {"_B1F_", TerminalNode(0)},
    {"_B1_C1_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_B2_C1_", "_B1_C2_")},
    {"_B1_C2_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_B2_C1_", "_B1F_")},
    {"_B2F_", TerminalNode(0)},
    {"_B2_C1_", Node([](const SuccessMap &m) { return m.at("hacker_1"); }, "_B3_C1_", "_B2_C2_")},
    {"_B2_C2_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_B3_C1_", "_B2F_")},
    {"_B3F_", TerminalNode(0)},
    {"_B3_C1_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_B4_C1_", "_B3_C2_")},
    {"_B3_C2_", Node([](const SuccessMap &m) { return m.at("hacker_1"); }, "_B4S_", "_B3F_")},
    {"_B4S_", TerminalNode(0)},
    {"_B4_C1_", Node([](const SuccessMap &m) { return m.at("hacker_1"); }, "_B5S_", "_B4S_")},
    {"_B5S_", TerminalNode(0)}};
};  // namespace tornium::oc::graph
#endif
