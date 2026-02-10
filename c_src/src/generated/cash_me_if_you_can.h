#ifndef CASH_ME_IF_YOU_CAN
#define CASH_ME_IF_YOU_CAN

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap cash_me_if_you_can {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C3_")},
{"_A2_C3_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C3_")},
{"_A3_C3_", Node([](const SuccessMap &m){ }, "_C1_C1_", "_B1F_")},
{"_A4S_", TerminalNode(1358000)},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ }, "_A4S_", "_B1_C1_")},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A6_C1_", "_B1_C1_")},
{"_A6_C1_", Node([](const SuccessMap &m){ }, "_A7S_", "_A8S_")},
{"_A7S_", TerminalNode(1554000)},
{"_A8S_", TerminalNode(1395000)},
{"_B1F_", TerminalNode(0)},
{"_B1_C1_", Node([](const SuccessMap &m){ }, "_B2_C1_", "_B1F_")},
{"_B2F_", TerminalNode(0)},
{"_B2_C1_", Node([](const SuccessMap &m){ }, "_B3S_", "_B2F_")},
{"_B3S_", TerminalNode(1167000)},
{"_C1F_", TerminalNode(0)},
{"_C1_C1_", Node([](const SuccessMap &m){ }, "_C2S_", "_C1F_")},
{"_C2S_", TerminalNode(860000)}
};
#endif
