#ifndef SMOKE_AND_WING_MIRRORS_H
#define SMOKE_AND_WING_MIRRORS_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap smoke_and_wing_mirrors {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ return m.at("thief_1"); }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A3_C1_", "_A2_C3_")},
{"_A2_C3_", Node([](const SuccessMap &m){ return m.at("thief_1"); }, "_A3_C1_", "_A2F_")},
{"_A3F_", TerminalNode(0)},
{"_A3_C1_", Node([](const SuccessMap &m){ return m.at("thief_1"); }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ return m.at("thief_1"); }, "_A4_C1_", "_A3F_")},
{"_A4F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ return (m.at("hustler_1") + m.at("hustler_2"))/2; }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ return m.at("hustler_2"); }, "_B2_C1_", "_A4_C3_")},
{"_A4_C3_", Node([](const SuccessMap &m){ return m.at("hustler_2"); }, "_B2_C1_", "_A4F_")},
{"_A5_C1_", Node([](const SuccessMap &m){ return m.at("thief_1"); }, "_A6_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_B3_C1_", "_C1F_")},
{"_A6F_", TerminalNode(0)},
{"_A6_C1_", Node([](const SuccessMap &m){ return m.at("hustler_1"); }, "_A7S_", "_A6_C2_")},
{"_A6_C2_", Node([](const SuccessMap &m){ return m.at("thief_1"); }, "_A8S_", "_A6_C3_")},
{"_A6_C3_", Node([](const SuccessMap &m){ return m.at("thief_1"); }, "_A9S_", "_A6F_")},
{"_A7S_", TerminalNode(0)},
{"_A8S_", TerminalNode(0)},
{"_A9S_", TerminalNode(0)},
{"_B2F_", TerminalNode(0)},
{"_B2_C1_", Node([](const SuccessMap &m){ return m.at("hustler_1"); }, "_B3_C1_", "_B2_C2_")},
{"_B2_C2_", Node([](const SuccessMap &m){ return m.at("hustler_2"); }, "_B3_C1_", "_B2F_")},
{"_B3S2_", TerminalNode(0)},
{"_B3S_", TerminalNode(0)},
{"_B3_C1_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_B3S_", "_B3S2_")},
{"_C1F_", TerminalNode(0)}
};
};
#endif
