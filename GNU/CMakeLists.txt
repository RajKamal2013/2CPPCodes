cmake_minimum_required(VERSION 3.10)
project(GNU)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(GNU
        src/main.cpp
        src/Codes/helloworld.cpp
        src/Codes/helloworld.h
        src/Codes/Sorting/qsort.h
        src/Codes/Sorting/qsort.cpp
        src/Codes/Util/IntegerFileGenerator.cpp
        src/Codes/Util/IntegerFileGenerator.h
        src/Codes/DS/AList.h
        src/Codes/DS/DList.h
        src/Codes/Exceptions/excep.h
        src/Codes/DS/Link.h
        src/Codes/DS/List.h
        src/Codes/DS/SList.h
        src/Codes/DS/Stack.h
        src/Codes/DS/AStack.h
        src/Codes/DS/LStack.h
        src/Codes/DS/Queue.h
        src/Codes/DS/AQueue.h
        src/Codes/DS/LQueue.h
        src/Coding/Array/NonConstructible.cpp
        src/Coding/Array/ThreeSum.h
        src/Coding/Array/twoSum.h
        src/Coding/Array/validateSubsequence.h
        src/Coding/Array/SortedSquare.h
        src/Coding/Array/SmallestDifference.h
        src/Coding/Array/MoveElementsToEnd.h
        src/Coding/Array/SpiralArrayPrint.h
        src/Coding/Array/Arraypeak.h
        src/Coding/Array/ArrayProduct.h
        src/Coding/Array/SubArraySort.h
        src/Coding/Array/LargestRange.h
        src/Coding/Array/ZigZagTraverseMatrix.h
        src/Coding/String/Palindrome.h
        src/Coding/String/StringAPITest.h
        src/Coding/String/ceaser_cipher.h
        src/Coding/String/RunLengthEncoding.h
        src/Coding/String/GenerateDocuments.h
        src/Coding/String/FirstNonRepeatingCharacter.h
        src/Codes/DS/BinarySearchTree.h
        src/Codes/DS/Graph.h
        src/Codes/DS/Heap.h
        src/Codes/Sorting/CSort.h
        src/Codes/Sorting/HSort.h
        src/Codes/Sorting/Msort.h
        src/Codes/Sorting/SortTest.h
        src/Codes/DS/DSTest.h
        src/Coding/DP/SubArraySum.h
        src/Coding/Recurssion/KnightTour.h
        src/Coding/Tree/BST.h
        src/Coding/Tree/BSTTest.h
        src/Coding/Tree/closestValue.h src/Coding/Tree/validateBST.h src/Coding/Tree/traverse.h src/Coding/Tree/branchSum.h src/Coding/Tree/NodeHeights.h src/Coding/Tree/mirror.h src/Coding/Tree/Diameter.h src/Coding/Tree/Successor.h src/Coding/Tree/CheckheightBalanced.h src/Coding/Tree/KthLargestValue.h src/Coding/Tree/minHeightBST.h src/Coding/List/DoubleLinkedList.h src/Coding/List/SingleLinkedList.h src/Coding/List/RemoveDuplicatesSortedLinkedList.h src/Coding/Recurssion/RatInMaze.h src/Coding/List/RemoveKNodeFromEnd.h src/Coding/List/LinkedList.h src/Coding/List/SumOfLists.h src/Coding/List/Loop.h src/Coding/List/ReverseList.h src/Coding/List/ShiftListByK.h src/Coding/Recurssion/NthFibonacci.h src/Coding/Searching/binarySearch.h src/Coding/Sorting/BubbleSort.h src/Coding/Sorting/InsertionSort.h src/Coding/Stack/MinMaxStack.h src/Coding/Stack/BalacedBrackets.h src/Coding/Stack/MaximumReactange.h src/Coding/Stack/SunSetView.h src/Coding/Stack/nextGreaterElement.h src/Coding/Stack/SortStack.h src/Coding/Searching/LargestThreeNumber.h src/Coding/String/LongestPalindrom.h src/Coding/String/GroupAnagram.h src/Coding/String/reverseLine.h src/Coding/String/MinCharacterForLine.h src/Coding/Heap/MinHeap.h src/Coding/String/TrieST.h src/Coding/String/RabinKarp.h src/Coding/Heap/mergeSortedArray.h src/Coding/Heap/MergeKSortedArray.h src/Coding/Heap/kSortedArray.h src/Coding/Heap/ContinuousMedian.h src/Coding/MergeInterval/MergeIntervals.h src/Coding/DP/ScoreRuns.h src/Coding/DP/coinChange.h src/Coding/DP/minCoinChange.h src/Coding/String/TinyUrl.h src/Coding/Array/mergeOverlappingIntervals.h src/Coding/Sorting/Qsort.h src/Coding/Sorting/HSort.h)
