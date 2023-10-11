cmake_minimum_required(VERSION 3.10)

project(object_detection)

# Set C++-Standardversion (C++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


#Add cpp
add_executable(object_detection src/main.cpp camera_module.cpp)

# Set out dir for Runtime
set_target_properties(object_detection PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)





