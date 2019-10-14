cmake_minimum_required(VERSION 3.14)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ass1 main.cpp matrix.cpp matrix.hpp connectivity_matrix.hpp connectivity_matrix.cpp stochastic_matrix.hpp stochastic_matrix.cpp transition_matrix.hpp teleportion_matrix.hpp teleportion_matrix.cpp transition_matrix.cpp column_matrix.hpp column_matrix.cpp)