//
// Created by Raj Kamal on 02/04/21.
//

#ifndef LLVM_QSORT_H
#define LLVM_QSORT_H

#include <vector>

class QSort {
    std::vector<int> arr;
    int size;
    int partition(int start, int end);
    void quicksort(int start, int end);
    void swap(int i, int j);

public:
    QSort(std::vector<int> vec, int size );
    std::vector<int> run();
};


#endif //LLVM_QSORT_H
