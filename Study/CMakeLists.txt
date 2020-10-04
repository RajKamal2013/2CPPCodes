cmake_minimum_required(VERSION 3.6)
project(CPPPractice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp C++_Practice/Algorithm_ToolBox/max_pairwise_product.cpp)
add_executable(CPPPractice ${SOURCE_FILES})