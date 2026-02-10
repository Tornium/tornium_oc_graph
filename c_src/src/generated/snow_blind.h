#ifndef SNOW_BLIND_H
#define SNOW_BLIND_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap snow_blind {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ return m.at("muscle_2"); }, "_A2_C1_", "_A1F_")},
{"_A2_C1_", Node([](const SuccessMap &m){ return m.at("hustler_1"); }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A3_C1_", "_B1_C1_")},
{"_A3_C1_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ return m.at("hustler_1"); }, "_A4_C1_", "_A4_C3_")},
{"_A4F_", TerminalNode(0)},
{"_A4S_", TerminalNode(6226000)},
{"_A4_C1_", Node([](const SuccessMap &m){ return m.at("hustler_1"); }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_A5_C1_", "_A4_C3_")},
{"_A4_C3_", Node([](const SuccessMap &m){ return m.at("hustler_1"); }, "_A4S_", "_A4F_")},
{"_A5F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ return m.at("hustler_1"); }, "_A6_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A6_C1_", "_A5F_")},
{"_A6F_", TerminalNode(0)},
{"_A6_C1_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A7_C1_", "_A6_C2_")},
{"_A6_C2_", Node([](const SuccessMap &m){ return m.at("hustler_1"); }, "_B7_C1_", "_A6_C3_")},
{"_A6_C3_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_B8S_", "_A6F_")},
{"_A7_C1_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A8S1_", "_A8S2_")},
{"_A8S1_", TerminalNode(10146000)},
{"_A8S2_", TerminalNode(9667000)},
{"_B1F1_", TerminalNode(0)},
{"_B1F2_", TerminalNode(0)},
{"_B1F3_", TerminalNode(0)},
{"_B1_C1_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_B1F3_", "_B1_C2_")},
{"_B1_C2_", Node([](const SuccessMap &m){ return m.at("muscle_2"); }, "_B1F2_", "_B1F1_")},
{"_B7S1_", TerminalNode(8654000)},
{"_B7S2_", TerminalNode(8100000)},
{"_B7_C1_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_B7S1_", "_B7S2_")},
{"_B8S_", TerminalNode(6689000)}
};
};
#endif
