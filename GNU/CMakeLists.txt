cmake_minimum_required(VERSION 3.16)
project(GNU)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(GNU
        src/Algo/binSearchInterval.cpp
        src/LeetCode/address_pointer_Test.cpp
        include/LeetCode/binary_search_tree.h
        include/LeetCode/binary_tree.h
        src/LeetCode/binary_tree_test.cpp
        src/LeetCode/permutation.cpp
        src/LeetCode/permutationsolution.cpp
        src/LeetCode/swap_pointer_test.cpp
        include/LeetCode/treeNode.h
        src/Threads/app.cpp
        src/Threads/hello_world.cpp
        src/Threads/helloWorld.cpp
        include/Threads/helloWorld.h
        src/Threads/thread1.cpp
        include/Threads/threadSafe_Stack.h)
