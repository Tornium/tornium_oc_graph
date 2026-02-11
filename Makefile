PRIV_DIR := $(MIX_APP_PATH)/priv
NIF_PATH := $(PRIV_DIR)/libtornium_oc_graph.so
PY_FFI_PATH := $(PRIV_DIR)/libtornium_oc_graph_py.so
C_SRC := $(shell pwd)/c_src
BUILD_TYPE ?= Debug

compile: c_src/build/ ${PRIV_DIR}
	@ cd c_src/build && cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -DFINE_INCLUDE_DIR=${FINE_INCLUDE_DIR} -DERTS_INCLUDE_DIR=${ERTS_INCLUDE_DIR} ..
	@ cd c_src/build && cmake --build . --config ${BUILD_TYPE}
	@ cp c_src/build/bindings/elixir/liblibtornium_oc_graph_ex.so ${NIF_PATH}
	@ cp c_src/build/bindings/python/liblibtornium_oc_graph_py.so ${PY_FFI_PATH}

c_src/build/:
	mkdir c_src/build/

${PRIV_DIR}:
	@ mkdir ${PRIV_DIR}

clean:
	rm -rf c_src/build/
