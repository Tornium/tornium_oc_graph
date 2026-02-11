file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)
add_library(libtornium_oc_graph_py SHARED ${SOURCES})

target_link_libraries(libtornium_oc_graph_py PRIVATE tornium_oc_graph_core)

# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../priv)

target_compile_options(libtornium_oc_graph_py PRIVATE -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion -Wunused-parameter -Wno-long-long -pedantic )
target_compile_features(libtornium_oc_graph_py PRIVATE cxx_std_20)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_options(libtornium_oc_graph_py PRIVATE -O0 -g)
endif()

target_include_directories(libtornium_oc_graph_py SYSTEM PRIVATE ${ERTS_INCLUDE_DIR} ${FINE_INCLUDE_DIR})
target_include_directories(libtornium_oc_graph_py PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(libtornium_oc_graph_py PRIVATE tornium_oc_graph_core)
