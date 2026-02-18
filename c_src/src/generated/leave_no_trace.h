#ifndef LEAVE_NO_TRACE_H
#define LEAVE_NO_TRACE_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap leave_no_trace{
    {"_A1F_", TerminalNode(0)},
    {"START", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_A2_C1_", "_A1_C2_")},
    {"_A1_C2_", Node([](const SuccessMap &m) { return m.at("negotiator_1"); }, "_A2_C1_", "_A1F_")},
    {"_A2_C1_", Node([](const SuccessMap &m) { return m.at("negotiator_1"); }, "_A3_C1_", "_A2_C2_")},
    {"_A2_C2_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_A3_C1_", "_B1_C1_")},
    {"_A3F_", TerminalNode(0)},
    {"_A3_C1_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_A4_C1_", "_A3_C2_")},
    {"_A3_C2_", Node([](const SuccessMap &m) { return m.at("negotiator_1"); }, "_A4_C1_", "_A3_C3_")},
    {"_A3_C3_", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_A4_C1_", "_A3F_")},
    {"_A4F_", TerminalNode(0)},
    {"_A4_C1_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_A5_C1_", "_A4_C2_")},
    {"_A4_C2_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_A6_C1_", "_A4F_")},
    {"_A5_C1_", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_A7_C1_", "_A6_C1_")},
    {"_A6F_", TerminalNode(0)},
    {"_A6S_", TerminalNode(8904000)},
    {"_A6_C1_", Node([](const SuccessMap &m) { return m.at("techie_1"); }, "_A8_C1_", "_A6_C2_")},
    {"_A6_C2_", Node([](const SuccessMap &m) { return m.at("negotiator_1"); }, "_A8_C1_", "_A6_C3_")},
    {"_A6_C3_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_A6S_", "_A6F_")},
    {"_A7S2_", TerminalNode(10364000)},
    {"_A7S_", TerminalNode(13366000)},
    {"_A7_C1_",
     Node([](const SuccessMap &m) { return (m.at("imitator_1") + m.at("negotiator_1")) / 2; }, "_A7S_", "_A7S2_")},
    {"_A8S1_", TerminalNode(10011000)},
    {"_A8S2_", TerminalNode(9938000)},
    {"_A8_C1_", Node([](const SuccessMap &m) { return m.at("negotiator_1"); }, "_A8S1_", "_A8S2_")},
    {"_B1F_", TerminalNode(0)},
    {"_B1_C1_", Node([](const SuccessMap &m) { return m.at("imitator_1"); }, "_B2_C1_", "_B1_C2_")},
    {"_B1_C2_", Node([](const SuccessMap &m) { return m.at("negotiator_1"); }, "_B2_C1_", "_B1F_")},
    {"_B2F_", TerminalNode(0)},
    {"_B2_C1_",
     Node([](const SuccessMap &m) { return (m.at("techie_1") + m.at("negotiator_1")) / 2; }, "_B3S_", "_B2F_")},
    {"_B3S_", TerminalNode(7637000)}};
};  // namespace tornium::oc::graph
#endif
