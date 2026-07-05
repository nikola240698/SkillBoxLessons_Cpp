cmake_minimum_required(VERSION 4.1)
project(MyComputer VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

