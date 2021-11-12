//
// Created by kamr on 11/12/2021.
//

#ifndef GNU_QSORT_H
#define GNU_QSORT_H

#include <vector>
#include <iostream>
using namespace std;

int qSort(vector<int> &arr, int start, int end) {
    int pivot = end;
    int currIdx = start;
    int lessThanPivot = start  - 1;


    while (currIdx < end) {
        if (arr[currIdx] <= arr[pivot]) {
            lessThanPivot = lessThanPivot + 1;
            swap(arr[currIdx], arr[lessThanPivot]);
        }
        currIdx = currIdx + 1;
    }

    lessThanPivot = lessThanPivot + 1;
    swap(arr[pivot], arr[lessThanPivot]);
    pivot = lessThanPivot;
    return pivot;
}

void
quickSortHelper(vector<int> &array, int start, int end) {
    if (start < end) {
        int pivot = qSort(array, start, end);
        quickSortHelper(array, start, pivot - 1);
        quickSortHelper(array, pivot + 1, end);
    }
}

vector<int> quickSort(vector<int> array) {
    if (array.size()== 0) {
        return {};
    }
    if (array.size() == 1) {
        return array;
    }

    int start, end;
    start = 0;
    end = array.size() - 1;
    quickSortHelper(array, start, end);
    return array;
}

void
test_Qsort()
{
    vector<int> arr = {};
    vector<int> sortedArr = {};
    vector<int> curr = {};

    cout <<"-------------------------------------" << endl;

    cout << "Input " << endl;
    arr = {1, 8, 2, 6, 5, 6, 3};
    curr = arr;
    for (auto &data:curr) {
        cout << data << " ";
    }
    cout << endl;
    cout << "Output " << endl;
    sortedArr = quickSort(curr);
    curr = sortedArr;
    for (auto &data:curr) {
        cout << data << " ";
    }
    cout << endl;
}
#endif //GNU_QSORT_H
