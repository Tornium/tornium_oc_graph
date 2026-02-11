#ifndef NO_RESERVE_H
#define NO_RESERVE_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap no_reserve{
    {"_A1F_", TerminalNode(0)},
    {"START", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_A2_C1_", "_A1_C2_")},
    {"_A1_C2_",
     Node([](const SuccessMap &m) { return (m.at("techie_1") + m.at("engineer_1")) / 2; }, "_A2_C1_", "_A1_C3_")},
    {"_A1_C3_", Node([](const SuccessMap &m) { return (m.at("thief_1") + m.at("techie_1")) / 2; }, "_A2_C1_", "_A1F_")},
    {"_A2F_", TerminalNode(0)},
    {"_A2_C1_", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_A3_C1_", "_A2_C2_")},
    {"_A2_C2_",
     Node([](const SuccessMap &m) { return (m.at("techie_1") + m.at("thief_1")) / 2; }, "_A3_C1_", "_A2_C3_")},
    {"_A2_C3_", Node([](const SuccessMap &m) { return m.at("engineer_1"); }, "_A3_C1_", "_A2F_")},
    {"_A3F_", TerminalNode(0)},
    {"_A3_C1_", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_A4_C1_", "_A3_C2_")},
    {"_A3_C2_", Node([](const SuccessMap &m) { return m.at("engineer_1"); }, "_A4_C1_", "_A3_C3_")},
    {"_A3_C3_", Node([](const SuccessMap &m) { return m.at("thief_1"); }, "_B4_C1_", "_A3F_")},
    {"_A4_C1_", Node([](const SuccessMap &m) { return m.at("thief_1"); }, "_A5_C1_", "_B4_C1_")},
    {"_A5_C1_", Node([](const SuccessMap &m) { return m.at("engineer_1"); }, "_A6_C1_", "_B5_C1_")},
    {"_A6_C1_", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_A7S_", "_B8_C1_")},
    {"_A7S_", TerminalNode(0)},
    {"_B4F_", TerminalNode(0)},
    {"_B4_C1_", Node([](const SuccessMap &m) { return m.at("engineer_1"); }, "_B5_C1_", "_B4F_")},
    {"_B5F_", TerminalNode(0)},
    {"_B5_C1_", Node([](const SuccessMap &m) { return m.at("thief_1"); }, "_B8_C1_", "_B5_C2_")},
    {"_B5_C2_", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_B6_C1_", "_B5F_")},
    {"_B6F_", TerminalNode(0)},
    {"_B6_C1_",
     Node([](const SuccessMap &m) { return (m.at("engineer_1") + m.at("thief_1")) / 2; }, "_B7S_", "_B6_C2_")},
    {"_B6_C2_", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_B7S_", "_B6F_")},
    {"_B7S_", TerminalNode(0)},
    {"_B8F_", TerminalNode(0)},
    {"_B8S_", TerminalNode(0)},
    {"_B8_C1_", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_B9S_", "_B8_C2_")},
    {"_B8_C2_", Node([](const SuccessMap &m) { return (m.at("thief_1") + m.at("engineer_1")) / 2; }, "_B8S_", "_B8F_")},
    {"_B9S_", TerminalNode(0)}};
};  // namespace tornium::oc::graph
#endif
