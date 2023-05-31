cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
add_definitions(-DMY_DEFINE="${CMAKE_SOURCE_DIR}/bin/")

get_filename_component(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
set(PROJECT_ROOT_DIR "methods") # YOUR NAME
project(methods)

set(HEADERS_DIRECTORY "./inc")
include_directories(${HEADERS_DIRECTORY})

file(GLOB_RECURSE SOURCES "src/main.cpp")
add_executable(${PROJECT_ROOT_DIR} ${SOURCES} src/FunkcjePomocnicze.cpp src/Metody_rozw.cpp inc/Rownania.h)
