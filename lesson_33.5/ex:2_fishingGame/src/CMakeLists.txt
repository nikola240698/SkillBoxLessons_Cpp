cmake_minimum_required(VERSION 4.1)


add_executable(SkillBoxApp
        main.cpp
        sector.cpp
        field.cpp
        m_input.cpp

        ${MY_INCLUDE_DIR}/fish.h
        ${MY_INCLUDE_DIR}/boot.h
        ${MY_INCLUDE_DIR}/sector.h
        ${MY_INCLUDE_DIR}/field.h
        ${MY_INCLUDE_DIR}/m_input.h

        )

target_include_directories(SkillBoxApp PUBLIC ${MY_INCLUDE_DIR})