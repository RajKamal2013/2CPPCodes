//
// Created by kamr on 11/13/2021.
//

#ifndef GNU_MERGESORT_H
#define GNU_MERGESORT_H

#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end) {
    int leftSize  = mid - start + 1;
    int rightSize = end - mid;
    int size = end - start + 1;

    vector<int> arrLeft(leftSize, 0);
    vector<int> arrRight(rightSize, 0);

    int idx = 0;

    for (idx = 0; idx < leftSize; idx++) {
        arrLeft[idx] = arr[start + idx];
    }

    for (idx = 0; idx < rightSize; idx++) {
        arrRight[idx] = arr[mid + idx + 1];
    }

    int rt, lt, sz;
    rt = 0;
    lt = 0;
    sz = start;


    while ((lt < leftSize) && (rt < rightSize)) {
        if (arrLeft[lt] < arrRight[rt]) {
            arr[sz] = arrLeft[lt];
            lt = lt + 1;
            sz = sz + 1;
        } else {
            arr[sz] = arrRight[rt];
            rt = rt + 1;
            sz = sz + 1;
        }
    }

    while (lt < leftSize) {
        arr[sz] = arrLeft[lt];
        sz = sz + 1;
        lt = lt + 1;
    }

    while (rt < rightSize) {
        arr[sz] = arrRight[rt];
        sz = sz + 1;
        rt = rt + 1;
    }
}

void mergeSortInt(vector<int> &array, int start, int end) {
    if (start < end) {
        int mid = (start + end)/2;
        mergeSortInt(array, start, mid);
        mergeSortInt(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

vector<int> mergeSort(vector<int> array) {
    if (array.size() == 0) {
        return {};
    }

    if (array.size() == 1) {
        return array;
    }

    int start  = 0;
    int end = array.size() - 1;

    mergeSortInt(array, start, end);
    return array;

}

void
test_mergeSort() {
    vector<int> arr = {8762, 654, 3008, 345, 87, 65, 234, 12, 2};
    vector<int> sortedArr;


    arr = {8762, 654, 3008, 345, 87, 65, 234, 12, 2, 100000};
    cout << "Input " << endl;
    for (auto &data:arr) {
        cout << data << " ";
    }
    cout << endl;
    sortedArr = mergeSort(arr);
    cout << "Output" << endl;
    for (auto &data:sortedArr) {
        cout << data << " ";
    }
    cout << endl;
}

#endif //GNU_MERGESORT_H
