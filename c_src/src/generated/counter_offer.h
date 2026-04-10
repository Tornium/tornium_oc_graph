#ifndef COUNTER_OFFER_H
#define COUNTER_OFFER_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap counter_offer{
    {"_A1F_", TerminalNode{0}},
    {"START", Node{[](const SuccessMap &m) { return sm_position(m, "robber_1"); }, "_A2_C1_", "_A1_C2_"}},
    {"_A1_C2_", Node{[](const SuccessMap &m) {
    return (sm_position(m, "robber_1") + sm_position(m, "picklock_1")) / 2;
}, "_A2_C1_", "_A1_C3_"}},
    {"_A1_C3_", Node{[](const SuccessMap &m) {
    return (sm_position(m, "looter_1") + sm_position(m, "picklock_1")) / 2;
}, "_A2_C1_", "_A1F_"}},
    {"_A2F_", TerminalNode{0}},
    {"_A2_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "engineer_1"); }, "_A3_C1_", "_A2_C2_"}},
    {"_A2_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "robber_1"); }, "_A3_C1_", "_A2F_"}},
    {"_A3_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "hacker_1"); }, "_A4_C1_", "_A3_C2_"}},
    {"_A3_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "hacker_1"); }, "_A4_C1_", "_B3_C1_"}},
    {"_A4F_", TerminalNode{9805354}},
    {"_A4_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "hacker_1"); }, "_A5_C1_", "_A4_C2_"}},
    {"_A4_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "engineer_1"); }, "_A5_C1_", "_A4F_"}},
    {"_A5F_", TerminalNode{9805354}},
    {"_A5S_", TerminalNode{19302615}},
    {"_A5_C1_", Node{[](const SuccessMap &m) {
    return (sm_position(m, "picklock_1") + sm_position(m, "robber_1")) / 2;
}, "_A6_C1_", "_A5_C2_"}},
    {"_A5_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "looter_1"); }, "_A5S_", "_A5_C3_"}},
    {"_A5_C3_", Node{[](const SuccessMap &m) { return (sm_position(m, "robber_1") + sm_position(m, "looter_1")) / 2; },
                     "_A5S_", "_A5F_"}},
    {"_A6_C1_", Node{[](const SuccessMap &m) {
    return (sm_position(m, "looter_1") + sm_position(m, "engineer_1")) / 2;
}, "_A7S_", "_A7S2_"}},
    {"_A7S2_", TerminalNode{13925354}},
    {"_A7S_", TerminalNode{30052612}},
    {"_B3F_", TerminalNode{0}},
    {"_B3_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "looter_1"); }, "_B4_C1_", "_B3_C2_"}},
    {"_B3_C2_", Node{[](const SuccessMap &m) {
    return (sm_position(m, "engineer_1") + sm_position(m, "looter_1")) / 2;
}, "_B4_C1_", "_B3F_"}},
    {"_B4F_", TerminalNode{0}},
    {"_B4_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "picklock_1"); }, "_B5S_", "_B4_C2_"}},
    {"_B4_C2_", Node{[](const SuccessMap &m) {
    return (sm_position(m, "engineer_1") + sm_position(m, "picklock_1")) / 2;
}, "_B5S_", "_B4F_"}},
    {"_B5S_", TerminalNode{12424208}}};
};  // namespace tornium::oc::graph
#endif
