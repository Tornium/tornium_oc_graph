#ifndef SNEAKY_GIT_GRAB
#define SNEAKY_GIT_GRAB

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap sneaky_git_grab {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"_A3F_", TerminalNode(0)},
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C3_")},
{"_A3_C3_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3F_")},
{"_A4F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4F_")},
{"_A5F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A6_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ }, "_A6_C1_", "_A5_C3_")},
{"_A5_C3_", Node([](const SuccessMap &m){ }, "_B6_C1_", "_A5F_")},
{"_A6_C1_", Node([](const SuccessMap &m){ }, "_A7_C1_", "_A6_C2_")},
{"_A6_C2_", Node([](const SuccessMap &m){ }, "_A8S_", "_A9S_")},
{"_A7S2_", TerminalNode(31742000)},
{"_A7S_", TerminalNode(36373000)},
{"_A7_C1_", Node([](const SuccessMap &m){ }, "_A7S_", "_A7S2_")},
{"_A8S_", TerminalNode(28098000)},
{"_A9S_", TerminalNode(24831000)},
{"_B6F_", TerminalNode(0)},
{"_B6_C1_", Node([](const SuccessMap &m){ }, "_B7S_", "_B6F_")},
{"_B7S_", TerminalNode(21636000)}
};
#endif
