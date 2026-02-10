#ifndef HONEY_TRAP_H
#define HONEY_TRAP_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap honey_trap {
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ return m.at("enforcer_1"); }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ return m.at("muscle_2"); }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ return m.at("enforcer_1"); }, "_A3_C1_", "_A2_C3_")},
{"_A2_C3_", Node([](const SuccessMap &m){ return m.at("muscle_2"); }, "_A3_C1_", "_A2F_")},
{"_A3_C1_", Node([](const SuccessMap &m){ return m.at("enforcer_1"); }, "_A4_C1_", "_B1_C1_")},
{"_A4F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ return m.at("enforcer_1"); }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_A5_C2_", "_A4F_")},
{"_A5F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ return m.at("muscle_2"); }, "_A6_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A6_C2_", "_A5F_")},
{"_A6S_", TerminalNode(18148000)},
{"_A6_C1_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_A7_C1_", "_A6_C2_")},
{"_A6_C2_", Node([](const SuccessMap &m){ return m.at("muscle_2"); }, "_A7_C1_", "_A6S_")},
{"_A7S_", TerminalNode(22866000)},
{"_A7_C1_", Node([](const SuccessMap &m){ return (m.at("enforcer_1") + m.at("muscle_1"))/2; }, "_A8S_", "_A7S_")},
{"_A8S_", TerminalNode(25172000)},
{"_B1F_", TerminalNode(0)},
{"_B1_C1_", Node([](const SuccessMap &m){ return m.at("muscle_2"); }, "_B2_C1_", "_B1_C2_")},
{"_B1_C2_", Node([](const SuccessMap &m){ return m.at("muscle_2"); }, "_B2_C1_", "_B1F_")},
{"_B2F_", TerminalNode(0)},
{"_B2S_", TerminalNode(15488000)},
{"_B2_C1_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_B2S_", "_B2_C2_")},
{"_B2_C2_", Node([](const SuccessMap &m){ return m.at("muscle_2"); }, "_B2S_", "_B2F_")}
};
};
#endif
