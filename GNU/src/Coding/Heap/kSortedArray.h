//
// Created by kamr on 11/9/2021.
//

#ifndef GNU_KSORTEDARRAY_H
#define GNU_KSORTEDARRAY_H

#include <vector>
#include <climits>
using namespace  std;

class MinHeap {
public:
    vector<int> heap;

    MinHeap(vector<int> arr = {}) {
        heap = arr;
        buildMinHeap();
    }

    void buildMinHeap() {
        for (int idx = heap.size()/2; idx >= 0; idx--) {
            siftDown(idx, heap.size() - 1);
        }
    }

    void siftDown(int currentIdx, int endIdx) {
        int temp, left, right, smaller;

        while (currentIdx < endIdx) {
            left = currentIdx * 2 + 1;
            right = currentIdx * 2 + 2;

            if ((left <= endIdx) && (heap[left] < heap[currentIdx])) {
                smaller = left;
            } else {
                smaller = currentIdx;
            }

            if ((right <= endIdx) && (heap[right] < heap[smaller])) {
                smaller = right;
            }

            if (currentIdx != smaller) {
                swap(heap[currentIdx], heap[smaller]);
                currentIdx = smaller;
            } else {
                break;
            }
        }
    }

    void siftUp(int currentIdx) {
        int parent;
        parent = (currentIdx - 1)/2;
        while(currentIdx >= 0) {
            if (heap[currentIdx] < heap[parent]) {
                swap(heap[currentIdx], heap[parent]);
                currentIdx = parent;
                parent = (currentIdx - 1)/2;
            } else {
                break;
            }
        }
    }

    void insert(int value) {
        heap.push_back(value);
        if (heap.size() == 1) {
            return;
        }
        siftUp(heap.size() - 1);

    }

    int removeMin() {
        if (heap.size() == 0) {
            return INT_MAX;
        }
        int min = heap[0];
        if (heap.size() == 1) {
            heap.pop_back();
            return min;
        } else {
            heap[0] = heap[heap.size() - 1];
            heap.pop_back();
            siftDown(0, heap.size()-1);
            return min;
        }
    }
};

vector<int> sortKSortedArray(vector<int> array, int k) {
    if ((array.size() == 0) || (array.size() == 1)) {
        return array;
    }
    int idx = 0;
    vector<int> arr = {};
    for (idx = 0; idx <= k; idx++) {
        if (idx < array.size()) {
            arr.push_back(array[idx]);
        }
    }

    MinHeap *heap = new MinHeap(arr);
    int currIdx = 0;
    int elmt = INT_MAX;

    for (idx = k + 1; idx < array.size(); idx++) {
        elmt = heap->removeMin();
        if (elmt == INT_MAX) {
                break;
        }
        array[currIdx]= elmt;
        currIdx++;
        heap->insert(array[idx]);
    }

    elmt = heap->removeMin();
    while (elmt != INT_MAX) {
        array[currIdx] = elmt;
        currIdx++;
        elmt = heap->removeMin();
    }
    return array;
}

void
test_kSortedArray() {
    vector<int> input;
    vector<int> output;
    int k;

    cout << "------------------------------------" << endl;
    input = {3, 2, 1, 5, 4, 7, 6, 5};
    k = 3;
    cout << "Input : " << k << " Sorted Array " << endl;
    for (auto data:input) {
        cout << data << " ";
    }
    cout << endl;

    cout << "Output -> Sorted Array:" << endl;
    output = sortKSortedArray(input, k);
    for (auto data:output) {
        cout << data << " ";
    }
    cout << endl;

    cout << "------------------------------------" << endl;
    input = {-1, -3, -4, 2, 1, 3};
    k = 2;
    cout << "Input : " << k << " Sorted Array " << endl;
    for (auto data:input) {
        cout << data << " ";
    }
    cout << endl;

    cout << "Output -> Sorted Array:" << endl;
    output = sortKSortedArray(input, k);
    for (auto data:output) {
        cout << data << " ";
    }
    cout << endl;


}
#endif //GNU_KSORTEDARRAY_H
