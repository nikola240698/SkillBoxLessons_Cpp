cmake_minimum_required(VERSION 3.16)

project(SkillBoxQtLessons VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Widgets
    Multimedia
    MultimediaWidgets
    Core
    Gui)

# set(PROJECT_SOURCES
#         main.cpp
#         mainwindow.cpp
#         mainwindow.h
#         mainwindow.ui
# )

add_executable(SkillBoxQtLessons main.cpp

    ${MY_RESOURCES_DIR}/resources.qrc

    ${MY_INCLUDE_DIR}/ImageButton.h
    ImageButton.cpp
    )

target_include_directories(SkillBoxQtLessons PUBLIC ${MY_INCLUDE_DIR})

target_link_libraries(SkillBoxQtLessons PRIVATE
    Qt::Widgets
    Qt::MultimediaWidgets
    Qt::Core
    Qt::Gui )

