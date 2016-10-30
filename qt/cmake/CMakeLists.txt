cmake_minimum_required (VERSION 2.8.12)
project (MyProject)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SrcDir ../src)

add_library (MyProjectLib
	${SrcDir}/mainwindow.h ${SrcDir}/mainwindow.cpp ${SrcDir}/mainwindow.ui)

target_link_libraries (MyProjectLib Qt5::Widgets)

add_executable(MyProject ${SrcDir}/main.cpp ${SrcDir}/resources/resources.qrc)
target_link_libraries (MyProject MyProjectLib)
