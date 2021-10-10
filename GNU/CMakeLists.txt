cmake_minimum_required(VERSION 3.10)
project(GNU)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(GNU
        src/main.cpp
        src/Codes/helloworld.cpp src/Codes/helloworld.h
        src/Codes/Sorting/qsort.h src/Codes/Sorting/qsort.cpp
        src/Codes/Util/IntegerFileGenerator.cpp src/Codes/Util/IntegerFileGenerator.h
        src/Codes/DS/AList.h
        src/Codes/DS/DList.h
        src/Codes/Exceptions/excep.h
        src/Codes/DS/Link.h src/Codes/DS/List.h src/Codes/DS/SList.h
        src/Codes/DS/Stack.h src/Codes/DS/AStack.h src/Codes/DS/LStack.h
        src/Codes/DS/Queue.h src/Codes/DS/AQueue.h src/Codes/DS/LQueue.h
        src/Coding/NonConstructible.cpp
        src/Coding/ThreeSum.h src/Coding/twoSum.h src/Coding/validateSubsequence.h src/Coding/SortedSquare.h src/Coding/SmallestDifference.h src/Coding/MoveElementsToEnd.h)
