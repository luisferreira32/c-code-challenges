cmake_minimum_required(VERSION 3.2)
project(runner)

set(APP_EXE runner)

set(SOURCE_FILES main.c)

add_executable(${APP_EXE} ${SOURCE_FILES})

# ------------ FOR EACH CHALLENGE ------------
# * add all the challenges CMakeLists.txt
# * link all the challenges
# * include directories
# --------------------------------------------

# anagram challenge
add_subdirectory(anagram)
target_link_libraries(${APP_EXE} anagram)
include_directories(anagram)
