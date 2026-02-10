#ifndef BEST_OF_THE_LOT
#define BEST_OF_THE_LOT

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap best_of_the_lot {
{"_A1F1_", TerminalNode(0)},
{"_A1F2_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ }, "_A1F2_", "_A1F1_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C3_")},
{"_A2_C3_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"_A3F_", TerminalNode(0)},
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ }, "_A4_C3_", "_A3_C3_")},
{"_A3_C3_", Node([](const SuccessMap &m){ }, "_A4_C3_", "_A3F_")},
{"_A4F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ }, "_B1_C1_", "_A4_C3_")},
{"_A4_C3_", Node([](const SuccessMap &m){ }, "_B1_C1_", "_A4F_")},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A6S_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ }, "_A7S_", "_A8S_")},
{"_A6S_", TerminalNode(0)},
{"_A7S_", TerminalNode(0)},
{"_A8S_", TerminalNode(0)},
{"_B1F_", TerminalNode(0)},
{"_B1_C1_", Node([](const SuccessMap &m){ }, "_B2S_", "_B1_C2_")},
{"_B1_C2_", Node([](const SuccessMap &m){ }, "_B3S_", "_B1F_")},
{"_B2S_", TerminalNode(0)},
{"_B3S_", TerminalNode(0)}
};
#endif
