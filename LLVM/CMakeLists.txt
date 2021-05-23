cmake_minimum_required(VERSION 3.16)
project(LLVM)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(LLVM
        src/Codes/helloworld.cpp
        src/Codes/helloworld.h
        src/Codes/Util/IntegerFileGenerator.h
        src/Codes/Util/IntegerFileGenerator.cpp
        src/Codes/Sorting/qsort.h
        src/Codes/Sorting/qsort.cpp
        src/Codes/main.cpp src/Codes/Sorting/Msort.h)
