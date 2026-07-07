cmake_minimum_required(VERSION 3.16)

add_executable(SkillBoxApp

        main.cpp
        toy.cpp
        dog.cpp

        ${MY_INCLUDE_DIR}/toy.h
        ${MY_INCLUDE_DIR}/dog.h
        )



target_include_directories(SkillBoxApp PUBLIC ${MY_INCLUDE_DIR})