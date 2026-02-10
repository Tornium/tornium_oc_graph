#ifndef BIDDING_WAR
#define BIDDING_WAR

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap bidding_war {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C3_")},
{"_A2_C3_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"_A3F_", TerminalNode(0)},
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C3_")},
{"_A3_C3_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3F_")},
{"_A4F2_", TerminalNode(0)},
{"_A4F_", TerminalNode(0)},
,
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A4_4_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ }, "_A4_4_", "_A4_C3_")},
{"_A4_C3_", Node([](const SuccessMap &m){ }, "_A4F2_", "_A4F_")},
{"_A5F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A6_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ }, "_A6_C2_", "_A5F_")},
{"_A6S2_", TerminalNode($78,511,000),
{"_A6S_", TerminalNode($92,173,000),
{"_A6_C1_", Node([](const SuccessMap &m){ }, "_A7_C1_", "_A6_C2_")},
{"_A6_C2_", Node([](const SuccessMap &m){ }, "_A6S_", "_A6S2_")},
{"_A7_C1_", Node([](const SuccessMap &m){ }, "_A8S_", "_A8S2_")},
{"_A8S2_", TerminalNode($101,236,000),
{"_A8S_", TerminalNode($131,852,000)
};
#endif
