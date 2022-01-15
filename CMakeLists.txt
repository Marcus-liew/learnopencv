cmake_minimum_required(VERSION 3.21)
project(learnopencv)

set(CMAKE_CXX_STANDARD 14)

#find_library(OpenCV)
find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

add_executable(learnopencv main.cpp quickdemo.cpp)

target_link_libraries(learnopencv ${OpenCV_LIBS})