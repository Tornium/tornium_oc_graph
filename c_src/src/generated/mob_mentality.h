#ifndef MOB_MENTALITY
#define MOB_MENTALITY

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap mob_mentality {
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
{"_A3_C3_", Node([](const SuccessMap &m){ }, "_D1_C1_", "_A3_C4_")},
{"_A3_C4_", Node([](const SuccessMap &m){ }, "_D1_C1_", "_D1_C1_")},
{"_A4F_Cont_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ }, "_B1_C1_", "_A4F_Cont_")},
{"_A5F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A7_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ }, "_A7S2_", "_A5F_")},
{"_A7S2_", TerminalNode($1,312,000),
{"_A7S_", TerminalNode($1,414,000),
{"_A7_C1_", Node([](const SuccessMap &m){ }, "_A7S_", "_A7S2_")},
{"_B1_C1_", Node([](const SuccessMap &m){ }, "_B2S_", "_B3S_")},
{"_B2S_", TerminalNode($1,191,000),
{"_B3S_", TerminalNode($1,063,000),
{"_D1_C1_", Node([](const SuccessMap &m){ }, "_D3S_", "_D2F_")},
{"_D2F_", TerminalNode(0)},
{"_D3S_", TerminalNode($741,000)
};
#endif
