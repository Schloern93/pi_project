cmake_minimum_required(VERSION 3.10)

project(object_detection)

# Set C++-Standardversion (C++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

#Set paths
set(PROJECT_INCLUDE_DIR "include")
set(SDK_DIR_A111 "/home/pi/wa/sdk/rpi_sparkfun")

#Add cpp
add_executable(object_detection src/main.cpp src/CameraModule.cpp)

# Set out dir for Runtime
set_target_properties(object_detection PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#include headers to target
target_include_directories(object_detection PUBLIC ${PROJECT_INCLUDE_DIR})





