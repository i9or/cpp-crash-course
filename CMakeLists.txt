cmake_minimum_required(VERSION 3.18)
project(cpp-crash-course)

set(CMAKE_CXX_STANDARD 17)

# set(SOURCE_FILES src/chapter1/hello.cpp)
set(SOURCE_FILES src/chapter2/types.cpp)

add_executable(cpp-crash-course ${SOURCE_FILES})
