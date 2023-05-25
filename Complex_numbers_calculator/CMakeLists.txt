cmake_minimum_required(VERSION 3.21)
<<<<<<< HEAD
project(DETERMINANT)

=======
project(COMPLEX)
>>>>>>> master-holder
set(CMAKE_CXX_STANDARD 14)

set(HEADERS_DIRECTORY "./inc")
include_directories(${HEADERS_DIRECTORY})

file(GLOB_RECURSE SOURCES "src/*.cpp" "tests/*.cpp")
<<<<<<< HEAD
add_executable(DETERMINANT ${SOURCES})

=======
add_executable(COMPLEX ${SOURCES})
>>>>>>> master-holder

