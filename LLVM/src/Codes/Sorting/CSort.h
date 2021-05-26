//
// Created by Raj Kamal on 26/05/21.
//

#ifndef LLVM_CSORT_H
#define LLVM_CSORT_H


class CSort {
    static void swap(std::vector<int> &arr, int i , int j) {
        int temp = arr[i];
        arr[i]= arr[j];
        arr[j] = temp;
    }

    static void CountingSort(std::vector<int> &arr, int range ) {
            std::vector<int> aux(arr.size());
            std::vector<int> rank(range);

            for (int i = 0; i< range; i++) {
                rank[i] = 0;
            }

            for (int i = 0;i < arr.size(); i++) {
                rank[arr[i]] = rank[arr[i]] + 1;
            }

            for (int i = 1; i < range; i++) {
                rank[i] = rank[i] + rank[i - 1];
            }

            for (int i = arr.size() - 1; i >= 0; i--) {
                aux[rank[arr[i]] - 1] = arr[i];
            }

            for(int i = 0;i < arr.size(); i++) {
                arr[i] = aux[i];
            }
    }

public:
    static void Sort(std::vector<int> &arr, int range) {
        if (arr.size() <= 1) {
            return;
        }

        CountingSort(arr, range);
    }

};


#endif //LLVM_CSORT_H
