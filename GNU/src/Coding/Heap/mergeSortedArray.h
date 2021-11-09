//
// Created by kamr on 11/9/2021.
//

#ifndef GNU_MERGESORTEDARRAY_H
#define GNU_MERGESORTEDARRAY_H

/*
 * Merge Sorted Array

    Given list of sorted Arrays and merge them to return sorted Array consisting of all the elements

    Input ->
        {1, 5, 9, 21}
        {-1, 0}
        {-124, 81, 121}
        {3, 6, 12, 20, 150}

    Output ->
        {-124, -1, 0, 1, 3, 5, 6, 9, 12, 20, 21, 81, 121, 150}

    Logic -> use minheap to heap all the sorted array.
 */

class MinHeapExternalSort {
public:
    vector<int> heapArray;
    MinHeapExternalSort(vector<int> array = {}) {
        buildHeap(array);
    }

    void buildHeap(vector<int> array) {
        if (array.size() == 0) {
            return;
        }

        for (int i = 0; i < array.size(); i++) {
            insert(array[i]);
        }
    }

    // keeps heap invarient as part of removal.
    void siftDown(vector<int> &heap, int currentIdx, int endIdx ) {
        if ((heap.size() == 0) || (heap.size() == 1)) {
            return;
        }
        int smaller, left, right, temp;

        while (currentIdx < endIdx) {
            left = 2 * currentIdx + 1;
            right = 2 * currentIdx + 2 ;

            // parent is greater, we need to push the parent down. parent has to be smaller .
            if ((left < endIdx) && (heap[currentIdx] > heap[left])) {
                smaller = left;
            } else { // parent is smaller then left
                smaller = currentIdx;
            }

            // check if right is smaller of parent and left
            if ((right < endIdx) && (heap[smaller] > heap[right])) {
                smaller = right;
            }

            // either left or right is smaller than parent. we need to swap it with parent
            if (currentIdx != smaller) {
                temp = heap[currentIdx];
                heap[currentIdx] = heap[smaller];
                heap[smaller] = temp;
                currentIdx = smaller;
            } else { // heap invarient is attached.
                break;
            }
        }
    }

    // keeps heap invarient as part of insertion buildheap.
    void siftUp(vector<int> &heap, int currentIdx) {
        if ((heap.size() == 0) || (heap.size() == 1)) {
            return;
        }

        int parent, temp;
        parent = (currentIdx - 1)/2;
        while ((currentIdx > 0) && (heap[parent] > heap[currentIdx])) {
            temp = heap[currentIdx];
            heap[currentIdx] = heap[parent];
            heap[parent] = temp;
            currentIdx = parent;
            parent = (currentIdx - 1)/2;
        }
    }

    void insert(int value) {
        heapArray.push_back(value);
        if (heapArray.size() == 1) {
            return;
        }
        int idx = heapArray.size() - 1;
        siftUp(heapArray, idx);
    }

    int removeMin() {
        if (heapArray.size() == 0) {
            return INT_MAX;
        }

        int min;
        min = heapArray[0];

        if (heapArray.size() == 1) {
            heapArray.pop_back();
            return min;
        }

        heapArray[0] = heapArray[heapArray.size() - 1];
        heapArray.pop_back();
        siftDown(heapArray, 0, heapArray.size());
        return min;
    }

    vector<int> heapSort() {
        vector<int> sortedArray = {};
        int val;
        if ((heapArray.size() == 0) || (heapArray.size() == 1)) {
            return heapArray;
        }

        while (heapArray.size() > 0) {
            val = removeMin();
            sortedArray.push_back(val);
        }
        return sortedArray;
    }
};

vector<int>
mergeSortedArrays(vector<vector<int>> arrays) {
    vector<int> sortedArray = {};
    // empty arrays
    if (arrays.size() == 0) {
        return {};
    }
    // just one element in arrays
    if (arrays.size() == 1) {
        return arrays[0];
    }

    // populate minheap
    MinHeapExternalSort *heap = new MinHeapExternalSort();
    for (auto &array:arrays) {
        heap->buildHeap(array);
    }

    // get all the element from heapSort(), this erase the heap too.
    sortedArray = heap->heapSort();

    return sortedArray;
}

void
test_mergeSortedArray() {
    vector<vector<int>> arrays = {};
    vector<int> array = {};
    vector<int> sortedArray = {};

    array = {1, 5, 9, 21};
    arrays.push_back(array);

    array = { -1, 0};
    arrays.push_back(array);

    array = {-124, 81, 121};
    arrays.push_back(array);

    array = {3, 6, 12, 20, 150};
    arrays.push_back(array);

    cout << "--------------------------------------------------------" << endl;
    cout << "Input : <arrays> " << endl;
    for (auto &list:arrays) {
        cout << "{ ";
        for (auto &data: list) {
            cout << data << " ";
        }
        cout << "}" << endl;
    }

    cout << "Output <Sorted Array afer merging sorted Array> " << endl;
    sortedArray = mergeSortedArrays(arrays);
    cout << "{ " ;
    for (auto &data:sortedArray) {
        cout << data << " ";
    }
    cout<< "}" << endl;


}

#endif //GNU_MERGESORTEDARRAY_H
