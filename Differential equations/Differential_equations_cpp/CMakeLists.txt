cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 17)
######################################
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
add_definitions(-DMY_DEFINE="${CMAKE_SOURCE_DIR}/bin/")

get_filename_component(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
set(PROJECT_ROOT_DIR "Differential_equations") # YOUR NAME
project(Differential_equations)

set(HEADERS_DIRECTORY "./inc")
include_directories(${HEADERS_DIRECTORY})

file(GLOB_RECURSE SOURCES "src/main.cpp")
add_executable(${PROJECT_ROOT_DIR} ${SOURCES} inc/Metody_rozw.h src/main.cpp inc/Rownania.h inc/FunkcjePomocnicze.h src/FunkcjePomocnicze.cpp src/Metody_rozw.cpp)