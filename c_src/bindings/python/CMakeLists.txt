find_package(Python COMPONENTS Development.Module REQUIRED)
python_add_library(_libtornium_oc_graph_py MODULE ffi.cpp)

target_link_libraries(_libtornium_oc_graph_py PRIVATE tornium_oc_graph_abi)

target_compile_options(_libtornium_oc_graph_py PRIVATE -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion -Wunused-parameter -Wno-long-long -pedantic )
target_compile_features(_libtornium_oc_graph_py PRIVATE cxx_std_20)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_options(_libtornium_oc_graph_py PRIVATE -O0 -g)
endif()

# target_include_directories(_libtornium_oc_graph_py PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(_libtornium_oc_graph_py PRIVATE tornium_oc_graph_abi)

set_target_properties(_libtornium_oc_graph_py PROPERTIES OUTPUT_NAME "_libtornium_oc_graph_py")

# Install both libs into the Python package directory so scikit-build-core
# bundles them into the wheel.
install(TARGETS _libtornium_oc_graph_py tornium_oc_graph_abi LIBRARY DESTINATION tornium_oc_graph)
# install(TARGETS tornium_oc_graph_core LIBRARY DESTINATION tornium_oc_graph)

