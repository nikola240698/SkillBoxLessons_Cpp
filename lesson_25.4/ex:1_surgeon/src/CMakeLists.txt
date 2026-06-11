cmake_minimum_required(VERSION 4.1)

add_executable(SkillBoxLessons main.cpp ${MY_INCLUDE_DIR}/surgeon.h)

target_include_directories(SkillBoxLessons PUBLIC ${MY_INCLUDE_DIR})
