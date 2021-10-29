//
// Created by kamr on 10/28/2021.
//

#ifndef GNU_HSORT_H
#define GNU_HSORT_H

class HSort {
    static void swap(std::vector<int> &arr, int i, int j ) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static void MaxHeapify(std::vector<int> &arr, int index, int heapSize) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest;

        if ((left < heapSize) && arr[left] > arr[index]) {
            largest = left;
        } else {
            largest = index;
        }

        if ((right < heapSize) && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr, largest, index);
            MaxHeapify(arr, largest, heapSize);
        }
    }

    static void BuildMaxHeap(std::vector<int> &arr) {
        int heapSize = arr.size();

        for (int i = arr.size()/2; i >= 0; i--) {
            MaxHeapify(arr, i, heapSize);
        }
    }

    static void HeapSort(std::vector<int> &arr) {
        int heapSize = arr.size();
        BuildMaxHeap(arr);
        for (int i = arr.size() - 1; i > 0; i--) {
            swap(arr, 0, i);
            heapSize = heapSize - 1;
            MaxHeapify(arr, 0, heapSize);
        }
    }

public:
    static void Sort(std::vector<int> &arr) {
        if (arr.size() == 1) {
            return;
        }
        HeapSort(arr);
    }
};

#endif //GNU_HSORT_H
