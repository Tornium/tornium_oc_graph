#ifndef COUNTER_OFFER
#define COUNTER_OFFER

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap counter_offer {
,
{"_A1_C3_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1F_")},
,
{"_B4_C2_", Node([](const SuccessMap &m){ }, "_B4_C2P_", "_B4F_")},
,
{"_B3F_", TerminalNode(0)},
,
{"_B5S_", TerminalNode(0)},
{"_A7S2_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C2_")},
{"_B3_C1_", Node([](const SuccessMap &m){ }, "_B4_C1_", "_B3_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ }, "_A5_C2P_", "_A5_C3_")},
{"_A6_C1_", Node([](const SuccessMap &m){ }, "_A6_C1P_", "_A7S2_")},
{"_A2F_", TerminalNode(0)},
,
{"_A1F_", TerminalNode(0)},
,
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A5_C1P_", "_A5_C2_")},
,
{"_A4_C2_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4F_")},
{"_A5F_", TerminalNode(0)},
{"_B4F_", TerminalNode(0)},
,
{"_A5S_", TerminalNode(0)},
,
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A3_C1P_", "_A3_C2_")},
,
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3_")},
{"_A4F_", TerminalNode(0)},
{"_A5_C3_", Node([](const SuccessMap &m){ }, "_A5_C3P_", "_A5F_")},
,
{"_A7S_", TerminalNode(0)},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
,
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ }, "_A3_C2P_", "_B3_C1_")},
{"_B3_C2_", Node([](const SuccessMap &m){ }, "_B4_C1_", "_B3F_")},
{"_B4_C1_", Node([](const SuccessMap &m){ }, "_B4_C1P_", "_B4_C2_")}
};
#endif
