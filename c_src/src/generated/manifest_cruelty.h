#ifndef MANIFEST_CRUELTY_H
#define MANIFEST_CRUELTY_H

#include "node.h"

using namespace tornium::oc::graph;

namespace tornium::oc::graph {
inline const NodeMap manifest_cruelty {
{"_A6_C2_", Node([](const SuccessMap &m){ return m.at("cat burglar_1"); }, "_A7_C1_", "_A6_C3_")},
{"_A1_C3_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A2_C1_", "_A1F_")},
{"_B6_C1_", Node([](const SuccessMap &m){ return (m.at("hacker_1") + m.at("cat burglar_1"))/2; }, "_B7S_", "_B6_C2_")},
{"_B4_C2_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_B5_C1_", "_B4_C3_")},
{"_B5F_", TerminalNode(0)},
{"_A4_C1_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A5_C1_", "_B4_C1_")},
{"_A5_C2_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_A6_C1_", "_A5F_")},
{"_A6_C1_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A7_C1_", "_A6_C2_")},
{"_B6F_", TerminalNode(0)},
{"_A2F_", TerminalNode(0)},
{"_A1F_", TerminalNode(0)},
{"_A5_C1_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_A6_C1_", "_A5_C2_")},
{"_A7_C2_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_A7S_", "_A7F_")},
{"_A5F_", TerminalNode(0)},
{"_B4F_", TerminalNode(0)},
{"_B6_C2_", Node([](const SuccessMap &m){ return (m.at("hacker_1") + m.at("cat burglar_1"))/2; }, "_B7S_", "_B6F_")},
{"_A3_C1_", Node([](const SuccessMap &m){ return m.at("cat burglar_1"); }, "_A4_C1_", "_B4_C1_")},
{"_A8S_", TerminalNode(0)},
{"_A2_C3_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_A3_C1_", "_A2F_")},
{"_A1_C2_", Node([](const SuccessMap &m){ return m.at("hacker_1"); }, "_A2_C1_", "_A1_C3_")},
{"_B5_C2_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_B6_C1_", "_B5F_")},
{"_A6F_", TerminalNode(0)},
{"_A7_C1_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_A8S_", "_A7_C2_")},
{"_A7F_", TerminalNode(0)},
{"_A7S_", TerminalNode(0)},
{"_B5_C1_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_B6_C1_", "_B5_C2_")},
{"_A2_C2_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_A3_C1_", "_A2_C3_")},
{"START", Node([](const SuccessMap &m){ return m.at("cat burglar_1"); }, "_A2_C1_", "_A1_C2_")},
{"_A2_C1_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_A3_C1_", "_A2_C2_")},
{"_B7S_", TerminalNode(0)},
{"_A6_C3_", Node([](const SuccessMap &m){ return (m.at("hacker_1") + m.at("cat burglar_1"))/2; }, "_A7_C1_", "_A6F_")},
{"_B4_C3_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_B5_C1_", "_B4F_")},
{"_B4_C1_", Node([](const SuccessMap &m){ static_assert(false, "Missing data: This needs to be manually entered"); }, "_B5_C1_", "_B4_C2_")}
};
};
#endif
