file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)
add_library(libtornium_oc_graph_py SHARED ${SOURCES})

target_link_libraries(libtornium_oc_graph_py PRIVATE tornium_oc_graph_core)

target_compile_options(libtornium_oc_graph_py PRIVATE -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion -Wunused-parameter -Wno-long-long -pedantic )
target_compile_features(libtornium_oc_graph_py PRIVATE cxx_std_20)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_options(libtornium_oc_graph_py PRIVATE -O0 -g)
endif()

target_include_directories(libtornium_oc_graph_py PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(libtornium_oc_graph_py PRIVATE tornium_oc_graph_core)

# Install both libs into the Python package directory so scikit-build-core
# bundles them into the wheel.
install(TARGETS libtornium_oc_graph_py LIBRARY DESTINATION tornium_oc_graph)
install(TARGETS tornium_oc_graph_core LIBRARY DESTINATION tornium_oc_graph)
