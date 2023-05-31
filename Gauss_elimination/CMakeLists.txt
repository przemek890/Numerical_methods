cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)
######################################
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
add_definitions(-DMY_DEFINE="${CMAKE_SOURCE_DIR}/bin/")

get_filename_component(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
set(PROJECT_ROOT_DIR "Gauss") # YOUR NAME
project(${PROJECT_ROOT_DIR})

set(HEADERS_DIRECTORY "./inc")
include_directories(${HEADERS_DIRECTORY})

file(GLOB_RECURSE SOURCES "src/main.cpp")
add_executable(${PROJECT_ROOT_DIR} ${SOURCES} inc/Gauss_Crouta.h inc/Funkcje_pom.h inc/Gauss.h src/Gaussa_Crouta.cpp src/Gauss.cpp src/Funkcje_pom.cpp)
