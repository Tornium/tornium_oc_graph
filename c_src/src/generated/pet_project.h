#ifndef PET_PROJECT_H
#define PET_PROJECT_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap pet_project{
    {"_A1F_", TerminalNode(0)},
    {"START", Node([](const SuccessMap &m) { return m.at("picklock_1"); }, "_A2_C1_", "_A1_C2_")},
    {"_A1_C2_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_B1_C1_", "_A1_C3_")},
    {"_A1_C3_", Node([](const SuccessMap &m) { return m.at("picklock_1"); }, "_A2_C1_", "_A1F_")},
    {"_A2_C1_", Node([](const SuccessMap &m) { return m.at("kidnapper_1"); }, "_A3_C1_", "_A2_C2_")},
    {"_A2_C2_", Node([](const SuccessMap &m) { return m.at("kidnapper_1"); }, "_A3_C1_", "_B1_C1_")},
    {"_A3_C1_", Node([](const SuccessMap &m) { return m.at("kidnapper_1"); }, "_A4_C1_", "_A3_C2_")},
    {"_A3_C2_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_A4_C1_", "_C1_C1_")},
    {"_A4_C1_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_A5_C1_", "_C1_C1_")},
    {"_A5_C1_", Node([](const SuccessMap &m) { return m.at("kidnapper_1"); }, "_A6_C1_", "_A5_C2_")},
    {"_A5_C2_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_A6_C1_", "_C1_C1_")},
    {"_A6F_", TerminalNode(0)},
    {"_A6_C1_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_A7_C1_", "_A6_C2_")},
    {"_A6_C2_", Node([](const SuccessMap &m) { return m.at("picklock_1"); }, "_A7_C1_", "_A6_C3_")},
    {"_A6_C3_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_A8S_", "_A6F_")},
    {"_A7F_", TerminalNode(0)},
    {"_A7S1_", TerminalNode(762000)},
    {"_A7S2_", TerminalNode(676000)},
    {"_A7_C1_", Node([](const SuccessMap &m) { return m.at("picklock_1"); }, "_A7S1_", "_A7_C2_")},
    {"_A7_C2_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_A7S2_", "_A7F_")},
    {"_A8S_", TerminalNode(600000)},
    {"_B1F_", TerminalNode(0)},
    {"_B1_C1_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_B2_C1_", "_B1_C2_")},
    {"_B1_C2_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_B2_C1_", "_B1F_")},
    {"_B2F_", TerminalNode(0)},
    {"_B2_C1_", Node([](const SuccessMap &m) { return m.at("kidnapper_1"); }, "_B3S_", "_B2F_")},
    {"_B3S_", TerminalNode(468000)},
    {"_C1F_", TerminalNode(0)},
    {"_C1_C1_",
     Node([](const SuccessMap &m) { return (m.at("kidnapper_1") + m.at("picklock_1")) / 2; }, "_C3S_", "_C1F_")},
    {"_C3S_", TerminalNode(491000)}};
};  // namespace tornium::oc::graph
#endif
