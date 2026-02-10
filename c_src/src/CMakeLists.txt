file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)
add_library(tornium_oc_graph_core SHARED ${SOURCES})

target_compile_options(tornium_oc_graph_core PRIVATE -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion -Wunused-parameter -Wno-long-long -pedantic )
target_compile_features(tornium_oc_graph_core PRIVATE cxx_std_20)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_options(tornium_oc_graph_core PRIVATE -O0 -g)
endif()

target_include_directories(tornium_oc_graph_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
