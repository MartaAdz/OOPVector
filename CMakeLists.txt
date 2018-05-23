# cmake_minimum_required(VERSION <specify CMake version here>)
project(uzduotys)

set(CMAKE_CXX_STANDARD 11)

include_directories()
SET(CMAKE_BUILD_TYPE distribution)
SET(CMAKE_CXX_FLAGS_DISTRIBUTION "-O3")
SET(CMAKE_C_FLAGS_DISTRIBUTION "-O3")

add_executable(uzduotys main.cpp timer.hpp vector.h)