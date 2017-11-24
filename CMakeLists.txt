cmake_minimum_required(VERSION 3.8)
project(List2_0)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp ListLib.cpp ListLib.h)
add_executable(List2_0 ${SOURCE_FILES})