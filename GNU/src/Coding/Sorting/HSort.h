//
// Created by kamr on 11/12/2021.
//

#ifndef GNU_HSORT_H
#define GNU_HSORT_H


#include <vector>
using namespace  std;


void siftDown(vector<int> &arr,  int currentIdx, int heapSize) {
    int left, right, larger;

    while(currentIdx < heapSize) {
        left = 2 *currentIdx + 1;
        right = 2 *currentIdx + 2;

        if ((left < heapSize) && (arr[left] > arr[currentIdx])) {
            larger = left;
        } else {
            larger = currentIdx;
        }

        if ((right < heapSize) && (arr[right] > arr[larger])) {
            larger = right;
        }

        if (larger != currentIdx ) {
            swap(arr[larger], arr[currentIdx]);
            currentIdx = larger;
        } else {
            break;
        }
    }
}

void siftUp(vector<int> &arr, int currentIdx, int heapSize) {
    int parent;

    parent = (currentIdx - 1)/2;
    while (currentIdx >= 0) {
        if (arr[currentIdx] > arr[parent]) {
            swap(arr[currentIdx], arr[parent]);
            currentIdx = parent;
            parent = (currentIdx - 1)/2;
        } else {
            break;
        }
    }
}

void buildHeap(vector<int> &arr) {
    int heapSize = arr.size();
    for (int idx = heapSize/2; idx >= 0; idx--) {
        siftDown(arr, idx, heapSize);
    }
}

int removeMax(vector<int>arr, int &heapSize) {
    int heapTop = arr[0];
    arr[0] = arr[heapSize - 1];
    heapSize = heapSize -1;
    return heapTop;
}

vector<int> heapSort(vector<int> array) {
    if (array.size() == 0) {
        return {};
    }
    if (array.size() == 1) {
        return  array;
    }

    buildHeap(array);
    int heapSize = array.size();
    while(heapSize != 1) {
        swap(array[heapSize -1], array[0]);
        heapSize = heapSize - 1;
        siftDown(array, 0, heapSize);
    }
    return array;
}

void
test_HSort()
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
    sortedArr = heapSort(curr);
    curr = sortedArr;
    for (auto &data:curr) {
        cout << data << " ";
    }
    cout << endl;
}

#endif //GNU_HSORT_H
