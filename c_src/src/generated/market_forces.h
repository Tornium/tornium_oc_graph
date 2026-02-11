#ifndef MARKET_FORCES_H
#define MARKET_FORCES_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap market_forces {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ return m.at("lookout_1"); }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ return m.at("enforcer_1"); }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ return m.at("negotiator_1"); }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A3_C1_", "_A2F_")},
{"_A3F_", TerminalNode(0)},
{"_A3_C1_", Node([](const SuccessMap &m){ return m.at("enforcer_1"); }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ return m.at("negotiator_1"); }, "_A4_C1_", "_A3_C3_")},
{"_A3_C3_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_B4_C1_", "_A3F_")},
{"_A4S_", TerminalNode(6046000)},
{"_A4_C1_", Node([](const SuccessMap &m){ return m.at("arsonist_1"); }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ return m.at("arsonist_1"); }, "_B5_C1_", "_A4S_")},
{"_A5S_", TerminalNode(5463000)},
{"_A5_C1_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A7_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ return (m.at("enforcer_1") + m.at("lookout_1"))/2; }, "_A7_C1_", "_A5S_")},
{"_A7S_", TerminalNode(7256000)},
{"_A7_C1_", Node([](const SuccessMap &m){ return m.at("negotiator_1"); }, "_A8_C1_", "_A7_C2_")},
{"_A7_C2_", Node([](const SuccessMap &m){ return m.at("negotiator_1"); }, "_A8_C1_", "_A7S_")},
{"_A8S2_", TerminalNode(7874000)},
{"_A8S_", TerminalNode(8610000)},
{"_A8_C1_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A8S_", "_A8S2_")},
{"_B4F_", TerminalNode(0)},
{"_B4_C1_", Node([](const SuccessMap &m){ return m.at("arsonist_1"); }, "_B5_C1_", "_B4F_")},
{"_B5F_", TerminalNode(0)},
{"_B5S_", TerminalNode(4810000)},
{"_B5_C1_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_B5S_", "_B5_C2_")},
{"_B5_C2_", Node([](const SuccessMap &m){ return (m.at("enforcer_1") + m.at("lookout_1"))/2; }, "_B5S_", "_B5F_")}
};
};
#endif
