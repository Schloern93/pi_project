cmake_minimum_required(VERSION 3.10)

project(obj_det)

# Setze die gewünschte C++-Standardversion (hier C++11)
set(CMAKE_CXX_STANDARD 11)


# Füge die Quellcode-Dateien hinzu
add_executable(object_detection src/main.cpp src/a111.cpp)

# Legen Sie das Ausgabeverzeichnis für das Ziel fest
set_target_properties(object_detection PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Füge Header-Dateien hinzu
target_include_directories(object_detection PRIVATE lib/rpi_sparkfun/include/ include/)

# Optional: Füge Bibliotheken hinzu (falls benötigt)
# target_link_libraries(mein_programm library_name)

# Optional: Konfiguriere weitere Build-Einstellungen
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Optional: Erzeuge ein Installationsziel
# install(TARGETS mein_programm DESTINATION bin)
