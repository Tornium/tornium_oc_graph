#ifndef MARKET_FORCES
#define MARKET_FORCES

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap market_forces {
{"_B5F_", TerminalNode(0)},
{"_B5S_", TerminalNode(0)},
{"_A3F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ }, "_A6_4_", "_A5S_")},
{"_A8_C1_", Node([](const SuccessMap &m){ }, "_A8S_", "_A8S2_")},
{"_A4S_", TerminalNode(0)},
{"_A2F_", TerminalNode(0)},
{"_A1F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A6_1_", "_A5_C2_")},
{"_A7_C2_", Node([](const SuccessMap &m){ }, "_A8_C1_", "_A7S_")},
{"_A4_C2_", Node([](const SuccessMap &m){ }, "_B5_C1_", "_A4S_")},
{"_A8S2_", TerminalNode($7,874,000),
{"_A3_C3_", Node([](const SuccessMap &m){ }, "_A3_C3P_", "_A3F_")},
{"_B4F_", TerminalNode(0)},
{"_A5S_", TerminalNode($5,463,000),
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A3_C1P_", "_A3_C2_")},
{"_A8S_", TerminalNode($8,610,000),
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1F_")},
{"_B5_C2_", Node([](const SuccessMap &m){ }, "_B5S_", "_B5F_")},
{"_A7_C1_", Node([](const SuccessMap &m){ }, "_A8_C1_", "_A7_C2_")},
{"_A7S_", TerminalNode(0)},
{"_B5_C1_", Node([](const SuccessMap &m){ }, "_B5S_", "_B5_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ }, "_A3_C2P_", "_A3_C3_")},
{"_B4_C1_", Node([](const SuccessMap &m){ }, "_B5_C1_", "_B4F_")}
};
#endif
