#ifndef BIDDING_WAR_H
#define BIDDING_WAR_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap bidding_war{
    {"_A1F_", TerminalNode(0)},
    {"START", Node([](const SuccessMap &m) { return m.at("bomber_1"); }, "_A2_C1_", "_A1_C2_")},
    {"_A1_C2_",
     Node([](const SuccessMap &m) { return (m.at("bomber_1") + m.at("bomber_2")) / 2; }, "_A2_C1_", "_A1_C3_")},
    {"_A1_C3_",
     Node([](const SuccessMap &m) { return (m.at("driver_1") + m.at("bomber_1")) / 2; }, "_A2_C1_", "_A1F_")},
    {"_A2F_", TerminalNode(0)},
    {"_A2_C1_", Node([](const SuccessMap &m) { return m.at("driver_1"); }, "_A3_C1_", "_A2_C2_")},
    {"_A2_C2_", Node([](const SuccessMap &m) { return m.at("driver_1"); }, "_A3_C1_", "_A2_C3_")},
    {"_A2_C3_", Node([](const SuccessMap &m) { return m.at("driver_1"); }, "_A3_C1_", "_A2F_")},
    {"_A3F_", TerminalNode(0)},
    {"_A3_C1_", Node([](const SuccessMap &m) { return m.at("robber_1"); }, "_A4_C1_", "_A3_C2_")},
    {"_A3_C2_", Node([](const SuccessMap &m) { return m.at("robber_2"); }, "_A4_C1_", "_A3_C3_")},
    {"_A3_C3_",
     Node([](const SuccessMap &m) { return (m.at("robber_1") + m.at("robber_2")) / 2; }, "_A4_C1_", "_A3F_")},
    {"_A4F2_", TerminalNode(0)},
    {"_A4F_", TerminalNode(0)},
    {"_A4_C1_", Node([](const SuccessMap &m) { return m.at("robber_3"); }, "_A5_C1_", "_A4_C2_")},
    {"_A4_C2_", Node([](const SuccessMap &m) { return m.at("bomber_2"); }, "_A5_C1_", "_A4_C3_")},
    {"_A4_C3_", Node([](const SuccessMap &m) { return m.at("robber_1"); }, "_A4F2_", "_A4F_")},
    {"_A5F_", TerminalNode(0)},
    {"_A5_C1_", Node([](const SuccessMap &m) { return m.at("robber_3"); }, "_A6_C1_", "_A5_C2_")},
    {"_A5_C2_", Node([](const SuccessMap &m) { return m.at("robber_2"); }, "_A6_C2_", "_A5F_")},
    {"_A6S2_", TerminalNode(78511000)},
    {"_A6S_", TerminalNode(92173000)},
    {"_A6_C1_",
     Node([](const SuccessMap &m) { return (m.at("robber_3") + m.at("driver_1")) / 2; }, "_A7_C1_", "_A6_C2_")},
    {"_A6_C2_", Node([](const SuccessMap &m) { return m.at("robber_2"); }, "_A6S_", "_A6S2_")},
    {"_A7_C1_", Node([](const SuccessMap &m) { return m.at("bomber_2"); }, "_A8S_", "_A8S2_")},
    {"_A8S2_", TerminalNode(101236000)},
    {"_A8S_", TerminalNode(131852000)}};
};  // namespace tornium::oc::graph
#endif
