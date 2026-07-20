cmake_minimum_required(VERSION 3.16)

project(SkillBoxQtLessons VERSION 0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(MY_RESOURCES_DIR ${CMAKE_SOURCE_DIR}/res)

add_subdirectory(src)
