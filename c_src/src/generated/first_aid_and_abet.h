#ifndef FIRST_AID_AND_ABET_H
#define FIRST_AID_AND_ABET_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap first_aid_and_abet{
    {"_A6_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "pickpocket_1"); }, "_A7S3_", "_A6F_"}},
    {"_A1_C3_", Node{[](const SuccessMap &m) {
    return (sm_position(m, "pickpocket_1") + sm_position(m, "picklock_1")) / 2;
}, "_A2_C1_", "_A1F_"}},
    {"_B6_C1_", Node{[](const SuccessMap &m) {
    static_assert(false, "Missing data: This needs to be manually entered");
}, "_B7S_", "_B6_C2_"}},
    {"_B4_C2_", Node{[](const SuccessMap &m) {
    return (sm_position(m, "picklock_1") + sm_position(m, "picklock_1")) / 2;
}, "_B5_C1_", "_B4F_"}},
    {"_B3F_", TerminalNode{0}},
    {"_B5F_", TerminalNode{0}},
    {"_A7S2_", TerminalNode{636496}},
    {"_A4_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "pickpocket_1"); }, "_A5_C1_", "_B4_C1_"}},
    {"_B3_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "pickpocket_1"); }, "_B4_C1_", "_B3F_"}},
    {"_A5_C2_", Node{[](const SuccessMap &m) {
    static_assert(false, "Missing data: This needs to be manually entered");
}, "_A6_C1_", "_A5_C3_"}},
    {"_A6_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "picklock_1"); }, "_A7S_", "_A7S2_"}},
    {"_B6F_", TerminalNode{0}},
    {"_A2F_", TerminalNode{0}},
    {"_A1F_", TerminalNode{0}},
    {"_A5_C1_", Node{[](const SuccessMap &m) {
    static_assert(false, "Missing data: This needs to be manually entered");
}, "_A6_C1_", "_A5_C2_"}},
    {"_A5F_", TerminalNode{0}},
    {"_B4F_", TerminalNode{0}},
    {"_B6_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "picklock_1"); }, "_B7S2_", "_B6F_"}},
    {"_A3_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "picklock_1"); }, "_A4_C1_", "_A3_C2_"}},
    {"_B7S2_", TerminalNode{422344}},
    {"_A1_C2_", Node{[](const SuccessMap &m) {
    static_assert(false, "Missing data: This needs to be manually entered");
}, "_A2_C1_", "_A1_C3_"}},
    {"_B5_C2_", Node{[](const SuccessMap &m) {
    return (sm_position(m, "picklock_1") + sm_position(m, "pickpocket_1")) / 2;
}, "_B6_C1_", "_B5F_"}},
    {"_A6F_", TerminalNode{0}},
    {"_A5_C3_", Node{[](const SuccessMap &m) {
    return (sm_position(m, "picklock_1") + sm_position(m, "pickpocket_1")) / 2;
}, "_A6_C2_", "_A5F_"}},
    {"_A7S3_", TerminalNode{556818}},
    {"_A7S_", TerminalNode{641366}},
    {"_B5_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "pickpocket_1"); }, "_B6_C1_", "_B5_C2_"}},
    {"_A2_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "pickpocket_1"); }, "_A3_C1_", "_A2F_"}},
    {"START", Node{[](const SuccessMap &m) { static_assert(false, "Missing data: This needs to be manually entered"); },
                   "_A2_C1_", "_A1_C2_"}},
    {"_A2_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "pickpocket_1"); }, "_A3_C1_", "_A2_C2_"}},
    {"_A3_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "picklock_1"); }, "_A4_C1_", "_B3_C1_"}},
    {"_B7S_", TerminalNode{384978}},
    {"_B4_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "picklock_1"); }, "_B5_C1_", "_B4_C2_"}}};
};  // namespace tornium::oc::graph
#endif
