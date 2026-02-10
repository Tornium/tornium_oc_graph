#ifndef BLAST_FROM_THE_PAST_H
#define BLAST_FROM_THE_PAST_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap blast_from_the_past {
{"_A10S_", TerminalNode(177517000)},
{"_A1F_", TerminalNode(0)},
{"START", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A2_C1_", "_A1_C2_")},
{"_A1_C2_", Node([](const SuccessMap &m){ return (m.at("picklock_1") + m.at("picklock_2"))/2; }, "_A2_C1_", "_A1_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A2_C1_", "_A1F_")},
{"_A2F_", TerminalNode(0)},
{"_A2_C1_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A3_C1_", "_A2_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ return m.at("picklock_1"); }, "_A3_C1_", "_A2_C3_")},
{"_A2_C3_", Node([](const SuccessMap &m){ return (m.at("picklock_1") + m.at("hacker_1"))/2; }, "_A3_C1_", "_A2F_")},
{"_A3F_", TerminalNode(0)},
{"_A3_C1_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A4_C1_", "_A3_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A4_C1_", "_A3F_")},
{"_A4F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ return m.at("engineer_1"); }, "_A5_C1_", "_A4_C2_")},
{"_A4_C2_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("engineer_1"))/2; }, "_A5_C1_", "_A4F_")},
{"_A5F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ return m.at("bomber_1"); }, "_A6_C1_", "_A5_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ return (m.at("engineer_1") + m.at("bomber_1"))/2; }, "_B6_C1_", "_A5F_")},
{"_A6_C1_", Node([](const SuccessMap &m){ return m.at("picklock_2"); }, "_A7_C1_", "_A6_C2_")},
{"_A6_C2_", Node([](const SuccessMap &m){ return (m.at("engineer_1") + m.at("picklock_2"))/2; }, "_A7_C1_", "_B6_C1_")},
{"_A7_C1_", Node([](const SuccessMap &m){ return m.at("picklock_1"); }, "_A8_C1_", "_A7_C2_")},
{"_A7_C2_", Node([](const SuccessMap &m){ return m.at("picklock_2"); }, "_A8_C1_", "_B7_C1_")},
{"_A8_C1_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A9S_", "_A10S_")},
{"_A9S_", TerminalNode(210569000)},
{"_B6_C1_", Node([](const SuccessMap &m){ return m.at("picklock_2"); }, "_B7_C1_", "_B7_C1_")},
{"_B7_C1_", Node([](const SuccessMap &m){ return m.at("picklock_1"); }, "_B8_C1_", "_B8_C1_")},
{"_B8S1_", TerminalNode(157774000)},
{"_B8S2_", TerminalNode(124694000)},
{"_B8_C1_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_B8S1_", "_B8S2_")}
};
};
#endif
