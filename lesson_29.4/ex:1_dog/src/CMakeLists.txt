cmake_minimum_required(VERSION 4.1)

add_executable(MyComputer
        main.cpp
        dog.cpp
        counting.cpp
        dancing.cpp
        swimming.cpp

        ${MY_INCLUDE_DIR}/counting.h
        ${MY_INCLUDE_DIR}/dancing.h
        ${MY_INCLUDE_DIR}/dog.h
        ${MY_INCLUDE_DIR}/swimming.h
        ${MY_INCLUDE_DIR}/talent.h


        )

target_include_directories(MyComputer PUBLIC ${MY_INCLUDE_DIR})