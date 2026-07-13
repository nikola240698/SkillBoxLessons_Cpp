cmake_minimum_required(VERSION 3.16)

add_executable(SkillBoxApp

        main.cpp
        m_input.cpp
        onlineStore.cpp

        ${MY_INCLUDE_DIR}/m_input.h
        ${MY_INCLUDE_DIR}/onlineStore.h

        )



target_include_directories(SkillBoxApp PUBLIC ${MY_INCLUDE_DIR})