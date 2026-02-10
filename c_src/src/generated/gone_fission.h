#ifndef GONE_FISSION
#define GONE_FISSION

#include "node.h"

using namespace tornium::oc::graph;

static const NodeMap gone_fission {
{"START", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3F_", TerminalNode(0)},
{"_A1_C3_", Node([](const SuccessMap &m){ }, "_A2_C1_", "_A1_C3F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ }, "_A3_C1_", "_A2F_")},
{"_A3F_", TerminalNode(0)},
{"_A3_C1_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3_C3_")},
{"_A3_C3_", Node([](const SuccessMap &m){ }, "_A4_C1_", "_A3F_")},
{"_A4F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4_C3_")},
{"_A4_C3_", Node([](const SuccessMap &m){ }, "_A5_C1_", "_A4F_")},
{"_A5F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ }, "_A6_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ }, "_A6_C1_", "_A5F_")},
{"_A6F_", TerminalNode(0)},
{"_A6_C1_", Node([](const SuccessMap &m){ }, "_A7_C1_", "_A6_C2_")},
{"_A6_C2_", Node([](const SuccessMap &m){ }, "_A7_C1_", "_A6_C3_")},
{"_A6_C3_", Node([](const SuccessMap &m){ }, "_A7_C1_", "_A6F_")},
{"_A7_C1_", Node([](const SuccessMap &m){ }, "_A8S_", "_A7_C2_")},
{"_A7_C2_", Node([](const SuccessMap &m){ }, "_A8S2_", "_A8S3_")},
{"_A8S2_", TerminalNode(0)},
{"_A8S3_", TerminalNode(0)},
{"_A8S_", TerminalNode(0)}
};
#endif
