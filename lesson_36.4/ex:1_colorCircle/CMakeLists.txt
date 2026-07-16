cmake_minimum_required(VERSION 4.2)
project(SkillBoxQtTutorial)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/nick/Qt/6.11.1/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(SkillBoxQtTutorial main.cpp)
target_link_libraries(SkillBoxQtTutorial
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

