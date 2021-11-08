//
// Created by kamr on 11/3/2021.
//

#ifndef GNU_BINARYSEARCH_H
#define GNU_BINARYSEARCH_H


int
binarySearchHelper(vector<int> array, int start, int end, int target) {
    /* return criteria */
    bool  dbgLog = false;
    if (start <= end) {
        int mid = (start + end) / 2;
        if (array[mid] == target) {
            if (dbgLog) {
                cout << "found idx at " << mid << endl;
            }
            return mid;
        } else if (array[mid] > target) {  /* we go left */
            return binarySearchHelper(array, start, mid - 1, target);
        } else {   /* go right */
            return binarySearchHelper(array, mid + 1, end, target);
        }
    } else {
        return -1;
    }
}

/* return index in array where array[i]  == target */
int
binarySearch(vector<int> array, int target) {
    /* array is empty */
    if (array.size() == 0) {
        return -1;
    }

    /* just one element */
    if (array.size() == 1) {
        if (array[0] == target) {
            return 0;
        } else {
            return -1;
        }
    }

    if (array.size() == 2) {
        if (array[0] == target){
            return 0;
        } else if (array[1] == target) {
            return 1;
        } else {
            return -1;
        }
    }

    return binarySearchHelper(array, 0, array.size() - 1, target);
}

void
test_binarySearch() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int value = 4;
    int idx  = binarySearch(arr, value);

    cout << "Input" << endl;
    for (auto &data:arr) {
        cout << data << " ";
    }
    cout << endl;

    cout << "Output:" <<endl;
    if (idx != -1) {
        cout << "Index of " << value << " in array :" << idx << endl;
    } else {
        cout << value << " does not exist in array" << endl;
    }
}

#endif //GNU_BINARYSEARCH_H
