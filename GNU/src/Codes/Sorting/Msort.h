//
// Created by kamr on 10/28/2021.
//

#ifndef GNU_MSORT_H
#define GNU_MSORT_H

class MSort {
    static void Merge(std::vector<int> &arr, int start, int mid, int end) {
        int lsize = mid - start + 1;
        int rsize = end - mid;
        int i, j, k;

        std::vector<int> larr(lsize);
        std::vector<int> rarr(rsize);

        for (i = 0; i < lsize; i++) {
            larr[i] = arr[start + i];
        }

        for (j = 0; j < rsize; j++) {
            rarr[j] = arr[mid + 1 + j];
        }

        i = j = 0;
        k = start;

        while ((i < lsize) && (j < rsize)) {
            if (larr[i] < rarr[j]) {
                arr[k] = larr[i];
                i = i + 1;
            } else {
                arr[k] = rarr[j];
                j = j + 1;
            }
            k = k + 1;
        }

        while (i < lsize) {
            arr[k] = larr[i];
            i = i + 1;
            k = k + 1;
        }

        while (j < rsize) {
            arr[k] = rarr[j];
            k = k + 1;
            j = j + 1;
        }
    }

    static void MergeSort(std::vector<int> &arr, int start, int end) {
        int mid;
        if (start < end) {
            mid = start + (end - start)/2;
            MergeSort(arr, start, mid);
            MergeSort(arr, mid + 1, end);
            Merge(arr, start, mid, end);
        }
    }

public:
    static void Sort(std::vector<int> &arr) {
        if (arr.size() == 1) {
            return;
        }
        MergeSort(arr, 0, arr.size() - 1);
    }
};

#endif //GNU_MSORT_H
