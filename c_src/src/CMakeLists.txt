file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)
add_library(tornium_oc_graph_lib SHARED ${SOURCES})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../priv)

target_compile_options(tornium_oc_graph_lib PRIVATE -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion -Wunused-parameter -Wno-long-long -pedantic )
target_compile_features(tornium_oc_graph_lib PRIVATE cxx_std_20)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_options(tornium_oc_graph_lib PRIVATE -O0 -g)
endif()

# target_compile_options(tornium_oc_graph_lib PRIVATE -fsanitize=address)
# target_link_options(tornium_oc_graph_lib PRIVATE -fsanitize=address)

target_include_directories(tornium_oc_graph_lib SYSTEM PRIVATE ${ERTS_INCLUDE_DIR} ${FINE_INCLUDE_DIR})
target_include_directories(tornium_oc_graph_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
