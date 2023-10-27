cmake_minimum_required(VERSION 3.10)

project(object_detection)

# Set C++-Standardversion (C++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
# Needs that GDB can debug
set(CMAKE_BUILD_TYPE Debug)

#Set paths
set(PROJECT_INCLUDE_DIR "include")
set(SDK_DIR_A111 "/home/pi/wa/sdk/rpi_sparkfun")

#Add static libs
add_library(libacc_detector_distance STATIC IMPORTED GLOBAL)
add_library(libacconeer STATIC IMPORTED GLOBAL)

# Set Properties for libs
set_target_properties(libacc_detector_distance PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${SDK_DIR_A111}/include)
set_target_properties(libacc_detector_distance PROPERTIES IMPORTED_LOCATION ${SDK_DIR_A111}/lib/libacc_detector_distance.a)

set_target_properties(libacconeer PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${SDK_DIR_A111}/include)
set_target_properties(libacconeer PROPERTIES IMPORTED_LOCATION ${SDK_DIR_A111}/lib/libacconeer.a)


#Add cpp
add_executable(object_detection
	src/main.cpp
	src/A111.cpp
	${SDK_DIR_A111}/source/acc_libspi.c
	${SDK_DIR_A111}/source/acc_libgpiod.c
	${SDK_DIR_A111}/source/acc_board_rpi_sparkfun.c	
	${SDK_DIR_A111}/source/acc_integration_linux.c
	${SDK_DIR_A111}/source/acc_integration_log.c
)
#add_executable(object_detection src/main.cpp)

# Set out dir for Runtime
set_target_properties(object_detection PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#include headers to target
target_include_directories(object_detection PUBLIC ${PROJECT_INCLUDE_DIR})
target_include_directories(object_detection PUBLIC ${SDK_DIR_A111}/include)


# Link libs
target_link_libraries(object_detection PUBLIC  
    libacc_detector_distance  
    libacconeer
    gpiod
)


