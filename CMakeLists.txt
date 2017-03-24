cmake_minimum_required(VERSION 2.8.3)
project(rviz_plugins)

find_package(catkin REQUIRED COMPONENTS rviz)

include_directories(${catkin_INCLUDE_DIRS})

## This plugin includes Qt widgets, so we must include Qt like so:
find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})

## We also use Ogre
include($ENV{ROS_ROOT}/core/rosbuild/FindPkgConfig.cmake)
pkg_check_modules(OGRE OGRE)
include_directories( ${OGRE_INCLUDE_DIRS} )
link_directories( ${OGRE_LIBRARY_DIRS} )

## I prefer the Qt signals and slots to avoid defining "emit", "slots",
## etc because they can conflict with boost signals, so define QT_NO_KEYWORDS here.
add_definitions(-DQT_NO_KEYWORDS)

## Here we specify which header files need to be run through "moc".
qt4_wrap_cpp(MOC_FILES src/distance.h src/display_distance.h)

set(SOURCE_FILES src/distance.cpp src/display_distance.cpp ${MOC_FILES})

set(LIBRARY_OUTPUT_PATH ${PROJECT_DIR}/lib)

## An rviz plugin is just a shared library, so here we declare the
## library to be called ``${PROJECT_NAME}`` and specify the list
## of source files we collected above in ``${SOURCE_FILES}``.
add_library(${PROJECT_NAME} ${SOURCE_FILES})

## Link the librarys
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES} ${OGRE_LIBRARIES})
