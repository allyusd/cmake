cmake_minimum_required (VERSION 2.8.12)
project (CMakeQt)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SrcDir ../src)

set(ALL_FILES
  ${SrcDir}/mainwindow.h ${SrcDir}/mainwindow.cpp ${SrcDir}/mainwindow.ui
  ${SrcDir}/tools/tool.h ${SrcDir}/tools/tool.cpp
  ${SrcDir}/resources/resources.qrc
)

add_library(${PROJECT_NAME}Lib ${ALL_FILES})

# for the VS folders to mirror the folder structure of your project
foreach(FILE ${ALL_FILES}) 
  get_filename_component(PARENT_DIR "${FILE}" PATH)

  # skip src or include
  #string(REGEX REPLACE "(\\./)?(src|include)/?" "" GROUP "${PARENT_DIR}")

  # skip ../
  string(REPLACE "../" "" GROUP "${PARENT_DIR}")

  # changes /'s to \\'s
  string(REPLACE "/" "\\" GROUP "${GROUP}")

  source_group("${GROUP}" FILES "${FILE}")
endforeach()

target_link_libraries(${PROJECT_NAME}Lib Qt5::Widgets)

add_executable(${PROJECT_NAME} ${SrcDir}/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}Lib)
