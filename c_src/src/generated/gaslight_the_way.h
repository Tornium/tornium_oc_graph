#ifndef GASLIGHT_THE_WAY_H
#define GASLIGHT_THE_WAY_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap gaslight_the_way {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ return (m.at("imitator_1") + m.at("looter_1"))/2; }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ return (m.at("imitator_1") + m.at("looter_1"))/2; }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ return (m.at("imitator_1") + m.at("looter_1"))/2; }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ return m.at("imitator_2"); }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ return m.at("imitator_2"); }, "_A3_C1_", "_A2F_")},
{"_A3F_", TerminalNode(0)},
{"_A3_C1_", Node([](const SuccessMap &m){ return m.at("imitator_3"); }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ return m.at("imitator_3"); }, "_B8_C1_", "_A3F_")},
{"_A4_C1_", Node([](const SuccessMap &m){ return m.at("looter_3"); }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ return m.at("looter_3"); }, "_A5_C1_", "_A5_C1_")},
{"_A5_C1_", Node([](const SuccessMap &m){ return (m.at("looter_2") + m.at("looter_3"))/2; }, "_A7_C1_", "_B7_C1_")},
{"_A7S2_", TerminalNode(0)},
{"_A7S_", TerminalNode(0)},
{"_A7_C1_", Node([](const SuccessMap &m){ return m.at("imitator_2"); }, "_A7S_", "_A7S2_")},
{"_B7S2_", TerminalNode(0)},
{"_B7S_", TerminalNode(0)},
{"_B7_C1_", Node([](const SuccessMap &m){ return m.at("imitator_2"); }, "_B7S_", "_B7S2_")},
{"_B8F_", TerminalNode(0)},
{"_B8_C1_", Node([](const SuccessMap &m){ return m.at("looter_3"); }, "_B9S_", "_B8F_")},
{"_B9S_", TerminalNode(0)}
};
};
#endif
