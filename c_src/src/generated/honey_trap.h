#ifndef HONEY_TRAP
#define HONEY_TRAP

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap honey_trap {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C3_")},
{"_A2_C3_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_B1_C1_")},
{"_A4F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ }, "_A5_C2_", "_A4F_")},
{"_A5F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A6_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ }, "_A6_C2_", "_A5F_")},
{"_A6S_", TerminalNode($18,148,000),
{"_A6_C1_", Node([](const SuccessMap &m){ }, "_A7_C1_", "_A6_C2_")},
{"_A6_C2_", Node([](const SuccessMap &m){ }, "_A7_C1_", "_A6S_")},
{"_A7S_", TerminalNode($22,866,000),
{"_A7_C1_", Node([](const SuccessMap &m){ }, "_A8S_", "_A7S_")},
{"_A8S_", TerminalNode($25,172,000),
{"_B1F_", TerminalNode(0)},
{"_B1_C1_", Node([](const SuccessMap &m){ }, "_B2_C1_", "_B1_C2_")},
{"_B1_C2_", Node([](const SuccessMap &m){ }, "_B2_C1_", "_B1F_")},
{"_B2F_", TerminalNode(0)},
{"_B2S_", TerminalNode($15,488,000),
{"_B2_C1_", Node([](const SuccessMap &m){ }, "_B2S_", "_B2_C2_")},
{"_B2_C2_", Node([](const SuccessMap &m){ }, "_B2S_", "_B2F_")}
};
#endif
