# set some dir vars
BIN_DIR := $(shell pwd)/bin
CMAKE_SRCS := $(shell find src -name "CMakeLists.txt")
CMAKE_BUILD_TYPE := release
CMAKE_BUILD_DIR = $(BIN_DIR)/$(CMAKE_BUILD_TYPE)
CMAKE_DEFS :=
CMAKE_BUILD_ARGS :=
CH_NAME := 

_pick_up_challenge:
ifndef CH_NAME
	$(error Missing CH_NAME variable (set it to one of the available challenges, e.g. anagram))
endif

compile:
	cmake $(CMAKE_DEFS) \
		-H./src \
		-B$(CMAKE_BUILD_DIR) \
		-G Ninja \
		-DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) 

build:
	cmake --build $(CMAKE_BUILD_DIR) $(CMAKE_BUILD_ARGS)

run: _pick_up_challenge
	$(CMAKE_BUILD_DIR)/challenge-runner $(CHALLENGE_NAME)

clean:
	rm -rf bin/
