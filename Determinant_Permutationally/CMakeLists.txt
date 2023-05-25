cmake_minimum_required(VERSION 3.21)
project(DETERMINANT)

set(CMAKE_CXX_STANDARD 14)

set(HEADERS_DIRECTORY "./inc")
include_directories(${HEADERS_DIRECTORY})

file(GLOB_RECURSE SOURCES "src/*.cpp" "tests/*.cpp")
add_executable(DETERMINANT ${SOURCES})


