#ifndef PLUCKING_THE_LOTUS_PETAL_H
#define PLUCKING_THE_LOTUS_PETAL_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap plucking_the_lotus_petal{
    {"_A6_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "muscle_1"); }, "_A7_C1_", "_B6_C1_"}},
    {"_C2F_", TerminalNode{0}},
    {"_B6_C1_", Node{[](const SuccessMap &m) { return (sm_position(m, "robber_1") + sm_position(m, "robber_2")) / 2; },
                     "_B7_C1_", "_B6_C2_"}},
    {"_C5_C1_", Node{[](const SuccessMap &m) { return (sm_position(m, "robber_1") + sm_position(m, "robber_2")) / 2; },
                     "_C6S_", "_C5_C2_"}},
    {"_B6_C2F_", TerminalNode{0}},
    {"_C4F_", TerminalNode{0}},
    {"_C5F_", TerminalNode{0}},
    {"_A3F_", TerminalNode{0}},
    {"_A4_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "robber_2"); }, "_A5_C1_", "_A4_C2_"}},
    {"_A5_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "hustler_1"); }, "_A6_C1_", "_B6_C1_"}},
    {"_C3_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "hustler_1"); }, "_C4_C1_", "_C3_C2_"}},
    {"_A6_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "muscle_1"); }, "_A7_C1_", "_A6_C2_"}},
    {"_A2F_", TerminalNode{0}},
    {"_C6S_", TerminalNode{7323000}},
    {"_A5_C1_", Node{[](const SuccessMap &m) { return (sm_position(m, "hustler_1") + sm_position(m, "muscle_1")) / 2; },
                     "_A6_C1_", "_A5_C2_"}},
    {"_C3F_", TerminalNode{0}},
    {"_C3_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "hustler_1"); }, "_C4_C1_", "_C3F_"}},
    {"_B7_C1_", Node{[](const SuccessMap &m) { return (sm_position(m, "robber_1") + sm_position(m, "robber_2")) / 2; },
                     "_B8S_", "_B7_C2_"}},
    {"_A4_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "robber_2"); }, "_A5_C1_", "_A4F_"}},
    {"_A8S2_", TerminalNode{8082000}},
    {"_A3_C3_", Node{[](const SuccessMap &m) { return (sm_position(m, "robber_2") + sm_position(m, "robber_1")) / 2; },
                     "_A4_C1_", "_A3F_"}},
    {"_C5_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "muscle_1"); }, "_C6S_", "_C5F_"}},
    {"_B6_C2_", Node{[](const SuccessMap &m) { return (sm_position(m, "robber_1") + sm_position(m, "robber_2")) / 2; },
                     "_B7_C1_", "_B6_C2F_"}},
    {"_A3_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "robber_1"); }, "_A4_C1_", "_A3_C2_"}},
    {"_A8S_", TerminalNode{8701000}},
    {"_A4F_", TerminalNode{0}},
    {"_A7_C1_", Node{[](const SuccessMap &m) { return (sm_position(m, "robber_1") + sm_position(m, "robber_2")) / 2; },
                     "_A8S_", "_A8S2_"}},
    {"_A2_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "muscle_1"); }, "_A3_C1_", "_A2F_"}},
    {"_C2_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "muscle_1"); }, "_C3_C1_", "_C2_C2_"}},
    {"_B7_C2F_", TerminalNode{0}},
    {"_B8S_", TerminalNode{6255000}},
    {"START", Node{[](const SuccessMap &m) { return sm_position(m, "hustler_1"); }, "_A2_C1_", "_C2_C1_"}},
    {"_C4_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "muscle_1"); }, "_C5_C1_", "_C4F_"}},
    {"_A2_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "muscle_1"); }, "_A3_C1_", "_A2_C2_"}},
    {"_A3_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "robber_1"); }, "_A4_C1_", "_A3_C3_"}},
    {"_C2_C2_", Node{[](const SuccessMap &m) { return sm_position(m, "muscle_1"); }, "_C3_C1_", "_C2F_"}},
    {"_B7_C2_", Node{[](const SuccessMap &m) { return (sm_position(m, "robber_1") + sm_position(m, "robber_2")) / 2; },
                     "_B8S_", "_B7_C2F_"}},
    {"_C4_C1_", Node{[](const SuccessMap &m) { return sm_position(m, "muscle_1"); }, "_C5_C1_", "_C4_C2_"}}};
};  // namespace tornium::oc::graph
#endif
