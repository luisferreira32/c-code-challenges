cmake_minimum_required(VERSION 3.2)

project(CProgram)

# Set Cmake variables
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c11 -O3")
# add in future? -lpthread

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

# Set a couple dir variables to use in the future
set(INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${INSTALL_BIN_DIR})

# Include external libraries
include_directories(${INSTALL_INCLUDE_DIR})

# Include internal libraries
include_directories(${INSTALL_LIB_DIR})

# Add the lib CMakeLists.txt
add_subdirectory(lib)

# Add the src CMakeLists.txt
add_subdirectory(src)

# Add the tests CMakeLists.txt
#add_subdirectory(test)


