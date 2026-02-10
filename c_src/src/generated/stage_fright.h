#ifndef STAGE_FRIGHT
#define STAGE_FRIGHT

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap stage_fright {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_B1_C1_")},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_B2_C1_")},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A6S_", "_A7S_")},
{"_A6S_", TerminalNode(Xanax x30),
{"_A7S_", TerminalNode(Xanax x25),
{"_B1F_", TerminalNode(0)},
{"_B1_C1_", Node([](const SuccessMap &m){ }, "_B2_C1_", "_B1_C2_")},
{"_B1_C2_", Node([](const SuccessMap &m){ }, "_B2_C1_", "_B1F_")},
{"_B2F_", TerminalNode(0)},
{"_B2S_", TerminalNode(Xanax x15),
{"_B2_C1_", Node([](const SuccessMap &m){ }, "_B3_C1_", "_B2_C2_")},
{"_B2_C2_", Node([](const SuccessMap &m){ }, "_B2S_", "_B2F_")},
{"_B3F_", TerminalNode(0)},
{"_B3_C1_", Node([](const SuccessMap &m){ }, "_B4S_", "_B3F_")},
{"_B4S_", TerminalNode(Xanax x19)
};
#endif
