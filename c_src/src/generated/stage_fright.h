#ifndef STAGE_FRIGHT_H
#define STAGE_FRIGHT_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap stage_fright{
    {"_A1F_", TerminalNode(0)},
    {"START",
     Node([](const SuccessMap &m) { return (m.at("lookout_1") + m.at("muscle_2")) / 2; }, "_A2_C1_", "_A1_C2_")},
    {"_A1_C2_",
     Node([](const SuccessMap &m) { return (m.at("lookout_1") + m.at("muscle_1")) / 2; }, "_A2_C1_", "_A1_C3_")},
    {"_A1_C3_",
     Node([](const SuccessMap &m) { return (m.at("enforcer_1") + m.at("muscle_3")) / 2; }, "_A2_C1_", "_A1F_")},
    {"_A2F_", TerminalNode(0)},
    {"_A2_C1_", Node([](const SuccessMap &m) { return m.at("sniper_1"); }, "_A3_C1_", "_A2_C2_")},
    {"_A2_C2_",
     Node([](const SuccessMap &m) { return (m.at("muscle_2") + m.at("muscle_1")) / 2; }, "_A3_C1_", "_A2F_")},
    {"_A3_C1_",
     Node([](const SuccessMap &m) { return (m.at("muscle_1") + m.at("muscle_3")) / 2; }, "_A4_C1_", "_B1_C1_")},
    {"_A4_C1_", Node([](const SuccessMap &m) { return m.at("enforcer_1"); }, "_A5_C1_", "_B2_C1_")},
    {"_A5_C1_", Node([](const SuccessMap &m) { return (m.at("lookout_1") + m.at("sniper_1")) / 2; }, "_A6S_", "_A7S_")},
    {"_A6S_", TerminalNode(0)},
    {"_A7S_", TerminalNode(0)},
    {"_B1F_", TerminalNode(0)},
    {"_B1_C1_", Node([](const SuccessMap &m) { return m.at("enforcer_1"); }, "_B2_C1_", "_B1_C2_")},
    {"_B1_C2_", Node([](const SuccessMap &m) { return m.at("sniper_1"); }, "_B2_C1_", "_B1F_")},
    {"_B2F_", TerminalNode(0)},
    {"_B2S_", TerminalNode(0)},
    {"_B2_C1_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_B3_C1_", "_B2_C2_")},
    {"_B2_C2_", Node([](const SuccessMap &m) { return (m.at("sniper_1") + m.at("driver_1")) / 2; }, "_B2S_", "_B2F_")},
    {"_B3F_", TerminalNode(0)},
    {"_B3_C1_", Node([](const SuccessMap &m) { return m.at("sniper_1"); }, "_B4S_", "_B3F_")},
    {"_B4S_", TerminalNode(0)}};
};  // namespace tornium::oc::graph
#endif
