# set some dir vars
BIN_DIR := $(shell pwd)/bin
CMAKE_SRCS := $(shell find src -name "CMakeLists.txt")
CMAKE_BUILD_TYPE := release
CMAKE_BUILD_DIR = $(BIN_DIR)/$(CMAKE_BUILD_TYPE)
CMAKE_DEFS :=
CMAKE_BUILD_ARGS :=
RUNNER_ARGS := 

_pick_runner_args:
ifndef RUNNER_ARGS
	$(echo "Missing RUNNER_ARGS variable, give them in the fashion --challenge <name> --solver <name>")
endif

compile:
	cmake $(CMAKE_DEFS) \
		-H. \
		-B$(CMAKE_BUILD_DIR) \
		-G Ninja \
		-DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) 

build:
	cmake --build $(CMAKE_BUILD_DIR) $(CMAKE_BUILD_ARGS)

run: _pick_runner_args
	$(BIN_DIR)/runner $(RUNNER_ARGS)

valrun: _pick_runner_args
	valgrind $(BIN_DIR)/runner $(RUNNER_ARGS)

clean:
	rm -rf bin/
