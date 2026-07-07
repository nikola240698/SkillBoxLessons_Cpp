cmake_minimum_required(VERSION 3.16)

add_executable(SkillBoxApp

        main.cpp
        toy.cpp
        shared_ptr_toy.cpp

        ${MY_INCLUDE_DIR}/toy.h
        ${MY_INCLUDE_DIR}/shared_ptr_toy.h)



target_include_directories(SkillBoxApp PUBLIC ${MY_INCLUDE_DIR})