//
// Created by Raj Kamal on 02/04/21.
//

#ifndef LLVM_QSORT_H
#define LLVM_QSORT_H

#include <vector>

class QSort {
    static void Swap(std::vector<int> &vec, int i, int j);
    static int Partition(std::vector<int> &vec, int start, int end);
    static void QuickSort(std::vector<int> &vec, int start, int end);

public:
    static void Sort(std::vector<int> &vec);
};

#endif //LLVM_QSORT_H
