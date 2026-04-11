cmake_minimum_required(VERSION 3.16)
project(tornium_oc_graph VERSION 0.2.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

option(BUILD_ELIXIR_NIF "Build Elixir NIF" ON)
option(BUILD_PYTHON_FFI "Build Python FFI bindings" ON)

add_subdirectory(src)
add_subdirectory(bindings/abi)

if(BUILD_ELIXIR_NIF)
	add_subdirectory(bindings/elixir)
endif()

if(SKBUILD OR BUILD_PYTHON_FFI)
	add_subdirectory(bindings/python)
endif()
