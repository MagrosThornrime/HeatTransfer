cmake_minimum_required(VERSION 3.26)
project(MES)
# set( CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++" )
# set( CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc" )
set(CMAKE_CXX_STANDARD 17)

add_executable(MES src/main.cpp
                src/b_part.cpp
                src/base_function.cpp
                src/l_part.cpp
                src/shift_function.cpp
                src/solver.cpp)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)