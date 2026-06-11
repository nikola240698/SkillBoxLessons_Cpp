cmake_minimum_required(VERSION 4.1)

add_executable(MyComputer
        main.cpp
        ram.cpp
        cpu.cpp
        gpu.cpp
        kbd.cpp
        disk.cpp

        ${MY_INCLUDE_DIR}/ram.h
        ${MY_INCLUDE_DIR}/cpu.h
        ${MY_INCLUDE_DIR}/gpu.h
        ${MY_INCLUDE_DIR}/kbd.h
        ${MY_INCLUDE_DIR}/disk.h

        )

target_include_directories(MyComputer PUBLIC ${MY_INCLUDE_DIR})