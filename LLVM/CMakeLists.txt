cmake_minimum_required(VERSION 3.16)
project(LLVM)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(LLVM
        src/Codes/helloworld.cpp
        src/Codes/helloworld.h
        src/Codes/IntegerFileGenerator.h
        src/Codes/IntegerFileGenerator.cpp
        src/Codes/qsort.h
        src/Codes/qsort.cpp
        src/Codes/main.cpp)
