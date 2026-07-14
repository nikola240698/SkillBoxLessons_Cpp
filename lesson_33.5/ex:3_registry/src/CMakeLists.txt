cmake_minimum_required(VERSION 4.1)


add_executable(SkillBoxApp
        main.cpp
        m_input.cpp
        select.cpp


        ${MY_INCLUDE_DIR}/m_input.h
        ${MY_INCLUDE_DIR}/registry.h
        ${MY_INCLUDE_DIR}/select.h

        )

target_include_directories(SkillBoxApp PUBLIC ${MY_INCLUDE_DIR})