#ifndef CRANE_REACTION
#define CRANE_REACTION

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap crane_reaction {
{"_A6_C2_", Node([](const SuccessMap &m){ }, "_B7_C1_", "_B6_C1_")},
{"_A8S3_", TerminalNode(0)},
{"_A1_C3_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1F_")},
{"_B6_C1_", Node([](const SuccessMap &m){ }, "_B7_C1_", "_B6_C2_")},
{"_B5F_", TerminalNode(0)},
{"_A7_C3_", Node([](const SuccessMap &m){ }, "_A8S3_", "_A7F_")},
{"_A3F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ }, "_A6_C1_", "_B5_C1_")},
{"_A6_C1_", Node([](const SuccessMap &m){ }, "_A7_C1_", "_A6_C2_")},
{"_B6F_", TerminalNode(0)},
{"_A2F_", TerminalNode(0)},
{"_A1F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A6_C1_", "_A5_C2_")},
{"_B7_C1_", Node([](const SuccessMap &m){ }, "_B7S_", "_B7_C2_")},
{"_A7_C2_", Node([](const SuccessMap &m){ }, "_A8S2_", "_A7_C3_")},
{"_A4_C2_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C3_")},
{"_A8S2_", TerminalNode(0)},
{"_B7F_", TerminalNode(0)},
{"_B6_C2_", Node([](const SuccessMap &m){ }, "_B7_C1_", "_B6F_")},
{"_A4_C3_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4F_")},
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C2_")},
{"_A8S_", TerminalNode(0)},
{"_B7S2_", TerminalNode(0)},
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3_")},
{"_B5_C2_", Node([](const SuccessMap &m){ }, "_B6_C1_", "_B5F_")},
{"_A4F_", TerminalNode(0)},
{"_A7_C1_", Node([](const SuccessMap &m){ }, "_A8S_", "_A7_C2_")},
{"_A7F_", TerminalNode(0)},
{"_B5_C1_", Node([](const SuccessMap &m){ }, "_B6_C1_", "_B5_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3F_")},
{"_B7S_", TerminalNode(0)},
{"_B7_C2_", Node([](const SuccessMap &m){ }, "_B7S2_", "_B7F_")}
};
#endif
