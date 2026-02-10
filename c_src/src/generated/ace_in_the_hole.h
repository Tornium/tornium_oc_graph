#ifndef ACE_IN_THE_HOLE_H
#define ACE_IN_THE_HOLE_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap ace_in_the_hole {
{"_A9S_", TerminalNode(458235000)},
{"_C6_C1_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_C7_C1_", "_C6_C2_")},
{"_B6_C1_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_B7S_", "_B6_C2_")},
{"_B2_C2_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_B3_C1_", "_B2F_")},
{"_D7S_", TerminalNode(353718000)},
{"_B4_C2_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_B5_C1_", "_B4F_")},
{"_C9S_", TerminalNode(341062000)},
{"_B2_C1_", Node([](const SuccessMap &m){ return m.at("muscle_2"); }, "_B3_C1_", "_B2_C2_")},
{"_B3F_", TerminalNode(0)},
{"_B5F_", TerminalNode(0)},
{"_A3F_", TerminalNode(0)},
{"_C6_C2_", Node([](const SuccessMap &m){ return (m.at("muscle_2") + m.at("impersonator_1"))/2; }, "_C9S_", "_C6F_")},
{"_A4_C1_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_A5_C1_", "_A4_C2_")},
{"_B3_C1_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_B4_C1_", "_B3_C2_")},
{"_A5_C2_", Node([](const SuccessMap &m){ return m.at("driver_1"); }, "_A6_C1_", "_A5_C3_")},
{"_A6_C1_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A7_C1_", "_C6_C1_")},
{"_D6F_", TerminalNode(0)},
{"_B6F_", TerminalNode(0)},
{"_A2F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ return m.at("driver_1"); }, "_A6_C1_", "_A5_C2_")},
{"_C6F_", TerminalNode(0)},
{"_A7_C2_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_A9S_", "_A10S_")},
{"_A4_C2_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A5_C1_", "_A4_C3_")},
{"_A3_C3_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A4_C1_", "_A3F_")},
{"_C7F_", TerminalNode(0)},
{"_B2F_", TerminalNode(0)},
{"_A10S_", TerminalNode(425684000)},
{"_B4F_", TerminalNode(0)},
{"_B6_C2_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_B7S_", "_B6F_")},
{"_A4_C3_", Node([](const SuccessMap &m){ return (m.at("impersonator_1") + m.at("muscle_2"))/2; }, "_A5_C1_", "_A4F_")},
{"_A3_C1_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A4_C1_", "_A3_C2_")},
{"_A8S_", TerminalNode(579740000)},
{"_A2_C3_", Node([](const SuccessMap &m){ return (m.at("muscle_2") + m.at("muscle_1"))/2; }, "_A3_C1_", "_A2F_")},
{"_D6_C1_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_D7S_", "_D6_C2_")},
{"_B5_C2_", Node([](const SuccessMap &m){ return m.at("driver_1"); }, "_D6_C1_", "_B5F_")},
{"_A4F_", TerminalNode(0)},
{"_A5_C3_", Node([](const SuccessMap &m){ return m.at("driver_1"); }, "_A6_C1_", "_C6_C1_")},
{"_A7_C1_", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A8S_", "_A7_C2_")},
{"_B5_C1_", Node([](const SuccessMap &m){ return m.at("driver_1"); }, "_B6_C1_", "_B5_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ return m.at("muscle_1"); }, "_A3_C1_", "_A2_C3_")},
{"START", Node([](const SuccessMap &m){ return m.at("impersonator_1"); }, "_A2_C1_", "_B2_C1_")},
{"_D6_C2_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_D7S_", "_D6F_")},
{"_A2_C1_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_A3_C1_", "_A2_C2_")},
{"_C8S_", TerminalNode(392257000)},
{"_A3_C2_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A4_C1_", "_A3_C3_")},
{"_B7S_", TerminalNode(451773000)},
{"_B3_C2_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_B4_C1_", "_B3F_")},
{"_B4_C1_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_B5_C1_", "_B4_C2_")},
{"_C7_C1_", Node([](const SuccessMap &m){ return (m.at("muscle_1") + m.at("muscle_2"))/2; }, "_C8S_", "_C7F_")}
};
};
#endif
