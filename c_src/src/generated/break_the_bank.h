#ifndef BREAK_THE_BANK_H
#define BREAK_THE_BANK_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap break_the_bank{
    {"_A10S_", TerminalNode(260655000)},
    {"_A1F_", TerminalNode(0)},
    {"START",
     Node([](const SuccessMap &m) { return (m.at("robber_1") + m.at("muscle_1")) / 2; }, "_A2_C1_", "_A1_C2_")},
    {"_A1_C2_", Node([](const SuccessMap &m) { return m.at("muscle_2"); }, "_A2_C1_", "_A1_C3_")},
    {"_A1_C3_", Node([](const SuccessMap &m) { return m.at("muscle_3"); }, "_A2_C1_", "_A1F_")},
    {"_A2_C1_",
     Node([](const SuccessMap &m) { return (m.at("muscle_2") + m.at("thief_1")) / 2; }, "_A3_C1_", "_A2_C2_")},
    {"_A2_C2_",
     Node([](const SuccessMap &m) { return (m.at("muscle_2") + m.at("thief_1")) / 2; }, "_A3_C1_", "_B1_C1_")},
    {"_A3_C1_", Node([](const SuccessMap &m) { return m.at("muscle_3"); }, "_A4_C1_", "_A3_C2_")},
    {"_A3_C2_",
     Node([](const SuccessMap &m) { return (m.at("thief_2") + m.at("muscle_3")) / 2; }, "_A4_C1_", "_A4_C2_")},
    {"_A4F_", TerminalNode(0)},
    {"_A4_C1_", Node([](const SuccessMap &m) { return m.at("thief_2"); }, "_A5_C1_", "_A4_C2_")},
    {"_A4_C2_", Node([](const SuccessMap &m) { return (m.at("robber_1") + m.at("thief_2")) / 2; }, "_A5_C1_", "_A4F_")},
    {"_A5F_", TerminalNode(0)},
    {"_A5_C1_", Node([](const SuccessMap &m) { return m.at("muscle_3"); }, "_A6_C1_", "_A5_C2_")},
    {"_A5_C2_",
     Node([](const SuccessMap &m) { return (m.at("muscle_3") + m.at("muscle_1")) / 2; }, "_A6_C1_", "_A5F_")},
    {"_A6_C1_",
     Node([](const SuccessMap &m) { return (m.at("robber_1") + m.at("muscle_1")) / 2; }, "_A7_C1_", "_A7_C2_")},
    {"_A7_C1_",
     Node([](const SuccessMap &m) { return (m.at("muscle_1") + m.at("robber_1")) / 2; }, "_A8_C1_", "_A7_C2_")},
    {"_A7_C2_", Node([](const SuccessMap &m) { return (m.at("robber_1") + m.at("muscle_1")) / 2; }, "_A9S_", "_A10S_")},
    {"_A8S2_", TerminalNode(354626000)},
    {"_A8S_", TerminalNode(359143000)},
    {"_A8_C1_", Node([](const SuccessMap &m) { return (m.at("robber_1") + m.at("thief_1")) / 2; }, "_A8S_", "_A8S2_")},
    {"_A9S_", TerminalNode(308754000)},
    {"_B1F_", TerminalNode(0)},
    {"_B1_C1_", Node([](const SuccessMap &m) { return m.at("thief_2"); }, "_B2_C1_", "_B1F_")},
    {"_B2F_", TerminalNode(0)},
    {"_B2_C1_", Node([](const SuccessMap &m) { return m.at("muscle_3"); }, "_B3S_", "_B2_C2_")},
    {"_B2_C2_", Node([](const SuccessMap &m) { return m.at("muscle_1"); }, "_B3S_", "_B2F_")},
    {"_B3S_", TerminalNode(212621000)}};
};  // namespace tornium::oc::graph
#endif
