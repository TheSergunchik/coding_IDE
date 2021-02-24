cmake_minimum_required(VERSION 3.15)
project(coding_IDE)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES code.h code.cpp response.h response.cpp mastermind.h mastermind.cpp main.cpp)

add_executable(ClionProject ${SOURCE_FILES})
