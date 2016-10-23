cmake_minimum_required (VERSION 2.8.12)
project (MyProject)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library (MyProjectLib mainwindow.cpp)

target_link_libraries (MyProjectLib Qt5::Widgets)
add_executable(MyProject main.cpp)
target_link_libraries (MyProject MyProjectLib)