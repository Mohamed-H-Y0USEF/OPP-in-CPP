cmake_minimum_required(VERSION 3.17)
project(Ask_fm)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ask_fm main.cpp askFmsrc.cpp askFmhed.h user.cpp)