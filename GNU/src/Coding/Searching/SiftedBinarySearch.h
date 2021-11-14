//
// Created by kamr on 11/14/2021.
//

#ifndef GNU_SIFTEDBINARYSEARCH_H
#define GNU_SIFTEDBINARYSEARCH_H

int binarySearch(vector<int> arr, int start, int end, int target) {
    if (start <= end) {
        int mid = (start + end)/2;
        if (arr[mid] > target) {
            return binarySearch(arr, start, mid - 1, target);
        } else if (arr[mid] < target) {
            return binarySearch(arr, mid + 1, end, target);
        } else {
            return mid;
        }
    } else {
        return -1;
    }
}

int shiftedBinarySearch(vector<int> array, int target) {
    if (array.size() == 0) {
        return -1;
    }
    if (array.size() == 1) {
        if (array[0] == target) {
            return 0;
        } else {
            return -1;
        }
    }

    int idx = 0;
    int prev = array[idx];
    int pos = -1;
    for (idx = 1; idx  < array.size(); idx++) {
        if (array[idx] < prev) {break;}
    }
    pos = binarySearch(array, 0, idx-1, target);
    if (pos != -1) {
        return pos;
    }

    pos = binarySearch(array, idx, array.size() - 1, target);
    if (pos != -1) {
        return pos;
    }
    return -1;
}

#endif //GNU_SIFTEDBINARYSEARCH_H
