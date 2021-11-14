//
// Created by kamr on 11/14/2021.
//

#ifndef GNU_SELECTIONSORT_H
#define GNU_SELECTIONSORT_H

/*
 * The selection sort algorithm sorts an array by repeatedly finding the minimum
 * element (considering ascending order) from unsorted part and putting it at the
 * beginning. The algorithm maintains two subarrays in a given array.
 * 1) The subarray which is already sorted.
 * 2) Remaining subarray which is unsorted.
 *
 * In every iteration of selection sort, the minimum element (considering ascending order)
 * from the unsorted subarray is picked and moved to the sorted subarray.
 * https://www.geeksforgeeks.org/selection-sort/
 *
 *
 */
vector<int> selectionSort(vector<int> array) {
    if (array.size() == 0) {
        return {};
    }
    if (array.size() == 1) {
        return array;
    }
    for (int idx = 0; idx < array.size(); idx++) {
        int minIdx = idx;
        for (int itr = idx + 1; itr < array.size(); itr++) {
            if (array[itr] < array[minIdx]) {
                minIdx = itr;
            }
        }
        swap(array[idx], array[minIdx]);
    }
    return array;;
}


#endif //GNU_SELECTIONSORT_H
