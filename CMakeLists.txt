cmake_minimum_required(VERSION 3.13)
project(1_0_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_0_1 main.cpp SynthesisLib/SynthesisInit.cpp SynthesisH/SynthesisInit.h)