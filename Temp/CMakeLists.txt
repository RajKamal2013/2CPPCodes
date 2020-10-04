cmake_minimum_required(VERSION 3.6)
project(CPP_Codes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES CPP_Codes/multiThreading/helloWorld.cpp CPP_Codes/multiThreading/helloWorld.h CPP_Codes/multiThreading/threadSafe_Stack.h CPP_Codes/multiThreading/app.cpp)
add_executable(CPP_Codes ${SOURCE_FILES})