cmake_minimum_required(VERSION 3.16)
project(exam)

set(CMAKE_CXX_STANDARD 17)

add_executable(exam main.cpp DotOnPlane.cpp DotOnPlane.h MyException.h DotInSpace.cpp DotInSpace.h)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")