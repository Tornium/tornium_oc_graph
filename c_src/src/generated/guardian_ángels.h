#ifndef GUARDIAN_ÁNGELS
#define GUARDIAN_ÁNGELS

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap guardian_ángels {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C3_")},
{"_A2_C3_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_B4_C1_")},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_B4_C1_")},
{"_A5F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A6_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ }, "_A6_C2_", "_A5_C3_")},
{"_A5_C3_", Node([](const SuccessMap &m){ }, "_A6_C2_", "_A5F_")},
{"_A6F_", TerminalNode(0)},
{"_A6_C1_", Node([](const SuccessMap &m){ }, "_A7S_", "_A6_C2_")},
{"_A6_C2_", Node([](const SuccessMap &m){ }, "_A8S_", "_A6_C3_")},
{"_A6_C3_", Node([](const SuccessMap &m){ }, "_A9S_", "_A6F_")},
{"_A7S_", TerminalNode(8551000)},
{"_A8S_", TerminalNode(7537000)},
{"_A9S_", TerminalNode(6296000)},
{"_B4F_", TerminalNode(0)},
{"_B4_C1_", Node([](const SuccessMap &m){ }, "_B5_C1_", "_B4_C2_")},
{"_B4_C2_", Node([](const SuccessMap &m){ }, "_B5_C1_", "_B4F_")},
{"_B5F_", TerminalNode(0)},
{"_B5_C1_", Node([](const SuccessMap &m){ }, "_B6S_", "_B5F_")},
{"_B6S_", TerminalNode(5190000)}
};
#endif
