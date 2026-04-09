file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)
add_library(tornium_oc_graph_abi STATIC ${SOURCES})

target_link_libraries(tornium_oc_graph_abi PRIVATE tornium_oc_graph_core)

set_target_properties(tornium_oc_graph_abi PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_compile_options(tornium_oc_graph_abi PRIVATE -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion -Wunused-parameter -Wno-long-long -pedantic )
target_compile_features(tornium_oc_graph_abi PRIVATE cxx_std_20)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_options(tornium_oc_graph_abi PRIVATE -O0 -g)
endif()

target_include_directories(tornium_oc_graph_abi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(tornium_oc_graph_abi PRIVATE tornium_oc_graph_core)
