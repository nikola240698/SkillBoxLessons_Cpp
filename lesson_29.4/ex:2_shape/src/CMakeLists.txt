cmake_minimum_required(VERSION 4.1)

add_executable(MyComputer
        main.cpp
        circle.cpp
        rectangle.cpp
        triangle.cpp
        shape.cpp

        ${MY_INCLUDE_DIR}/shape.h
        ${MY_INCLUDE_DIR}/circle.h
        ${MY_INCLUDE_DIR}/rectangle.h
        ${MY_INCLUDE_DIR}/triangle.h


        )

target_include_directories(MyComputer PUBLIC ${MY_INCLUDE_DIR})