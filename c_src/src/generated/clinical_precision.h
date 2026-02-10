#ifndef CLINICAL_PRECISION_H
#define CLINICAL_PRECISION_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap clinical_precision {
{"_A9S_", TerminalNode(105399000)},
{"_A6_C2_", Node([](const SuccessMap &m){ return m.at("assassin_1"); }, "_A7_C1_", "_A6_C3_")},
{"_C6_C1_", Node([](const SuccessMap &m){ return m.at("imitator_1"); }, "_C7S_", "_C6F_")},
{"_A1_C3_", Node([](const SuccessMap &m){ return (m.at("cat burglar_1") + m.at("cleaner_1"))/2; }, "_A2_C1_", "_A1F_")},
{"_C5_C1_", Node([](const SuccessMap &m){ return m.at("cleaner_1"); }, "_C6_C1_", "_C5_C2_")},
{"_C7S_", TerminalNode(88061000)},
{"_B3F_", TerminalNode(0)},
{"_B5S_", TerminalNode(65631000)},
{"_C5F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ return m.at("cleaner_1"); }, "_A5_C1_", "_A4_C2_")},
{"_B3_C1_", Node([](const SuccessMap &m){ return m.at("imitator_1"); }, "_B4_C1_", "_B3_C2_")},
{"_A6_C1_", Node([](const SuccessMap &m){ return m.at("assassin_1"); }, "_A7_C1_", "_A6_C2_")},
{"_A1F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ return (m.at("imitator_1") + m.at("assassin_1"))/2; }, "_A6_C1_", "_C5_C1_")},
{"_C6F_", TerminalNode(0)},
{"_A4_C2_", Node([](const SuccessMap &m){ return m.at("cat burglar_1"); }, "_A5_C1_", "_A4F_")},
{"_C5_C2_", Node([](const SuccessMap &m){ return (m.at("cat burglar_1") + m.at("cleaner_1"))/2; }, "_C6_C1_", "_C5F_")},
{"_B4F_", TerminalNode(0)},
{"_A3_C1_", Node([](const SuccessMap &m){ return m.at("cleaner_1"); }, "_A4_C1_", "_A3_C2_")},
{"_A8S_", TerminalNode(115652000)},
{"_A1_C2_", Node([](const SuccessMap &m){ return (m.at("assassin_1") + m.at("cat burglar_1"))/2; }, "_A2_C1_", "_A1_C3_")},
{"_A4F_", TerminalNode(0)},
{"_A6F_", TerminalNode(0)},
{"_A7_C1_", Node([](const SuccessMap &m){ return (m.at("assassin_1") + m.at("cleaner_1"))/2; }, "_A8S_", "_A9S_")},
{"_B5_C1_", Node([](const SuccessMap &m){ return (m.at("cleaner_1") + m.at("assassin_1"))/2; }, "_B6S_", "_B5S_")},
{"_A2_C2_", Node([](const SuccessMap &m){ return m.at("assassin_1"); }, "_A3_C1_", "_B3_C1_")},
{"START", Node([](const SuccessMap &m){ return m.at("cat burglar_1"); }, "_A2_C1_", "_A1_C2_")},
{"_A2_C1_", Node([](const SuccessMap &m){ return m.at("assassin_1"); }, "_A3_C1_", "_A2_C2_")},
{"_A3_C2_", Node([](const SuccessMap &m){ return m.at("cleaner_1"); }, "_A4_C1_", "_B3_C1_")},
{"_B6S_", TerminalNode(79989000)},
{"_A6_C3_", Node([](const SuccessMap &m){ return m.at("imitator_1"); }, "_A6S_", "_A6F_")},
{"_B3_C2_", Node([](const SuccessMap &m){ return (m.at("assassin_1") + m.at("cleaner_1"))/2; }, "_B4_C1_", "_B3F_")},
{"_A6S_", TerminalNode(91091000)},
{"_B4_C1_", Node([](const SuccessMap &m){ return m.at("imitator_1"); }, "_B5_C1_", "_B4F_")}
};
};
#endif
