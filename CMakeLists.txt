cmake_minimum_required(VERSION 3.26)
project(MES)
# set( CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++" )
# set( CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc" )
set(CMAKE_CXX_STANDARD 17)

add_executable(MES main.cpp
                b_part.cpp
                base_function.cpp
                l_part.cpp
                shift_function.cpp
                solver.cpp)