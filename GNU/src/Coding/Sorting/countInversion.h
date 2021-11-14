//
// Created by kamr on 11/14/2021.
//

#ifndef GNU_COUNTINVERSION_H
#define GNU_COUNTINVERSION_H

#include <vector>
using namespace std;


int mergeAndCount(vector<int> &arr, int start, int mid, int end) {

    int ltSize = mid - start + 1;
    int rtSize = end - mid;
    int inversionCount = 0;

    vector<int> arrLeft(ltSize, 0);
    vector<int> arrRight(rtSize, 0);


    for (int idx = 0; idx < ltSize; idx++) {
        arrLeft[idx] = arr[start + idx];
    }

    for (int idx = 0; idx < rtSize; idx++) {
        arrRight[idx] = arr[mid + 1 + idx];
    }


    int arrIdx, leftIdx, rightIdx;
    leftIdx = rightIdx = 0;
    arrIdx = start;

    while ((leftIdx < ltSize) && (rightIdx < rtSize)) {
        if (arrLeft[leftIdx] > arrRight[rightIdx]) {
            int tempIdx = leftIdx;
            while (tempIdx < ltSize) {
                if (arrLeft[tempIdx] > arrRight[rightIdx]) {
                    inversionCount = inversionCount + 1;
                    tempIdx = tempIdx + 1;
                } else { break;}
            }
            arr[arrIdx] = arrRight[rightIdx];
            rightIdx = rightIdx + 1;
            arrIdx = arrIdx + 1;
        } else {
            arr[arrIdx]  = arrLeft[leftIdx];
            arrIdx = arrIdx + 1;
            leftIdx = leftIdx + 1;
        }
    }

    while (leftIdx < ltSize) {
        arr[arrIdx] = arrLeft[leftIdx];
        leftIdx = leftIdx + 1;
        arrIdx = arrIdx + 1;
    }

    while (rightIdx < rtSize) {
        arr[arrIdx]  = arrRight[rightIdx];
        arrIdx = arrIdx + 1;
        rightIdx = rightIdx + 1;
    }

    return inversionCount;

}

int countInversionsInt(vector<int> &array, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        int ltCount = countInversionsInt(array, start, mid);
        int rtCount = countInversionsInt(array, mid + 1, end);
        int mergeCount = mergeAndCount(array, start, mid, end);
/*
        cout << "Start:" << start << " End: " << end << " Mid: " << mid;
        cout << " LtCount: " << ltCount << " rtCount:" << rtCount << " MergeCount:" << mergeCount << endl;
*/
        int totalCount = ltCount + rtCount + mergeCount;
        return totalCount;
    } else {
        return 0;
    }

}


int countInversions(vector<int> array) {
    if (array.size() == 0) {
        return 0;
    }

    if (array.size() == 1) {
        return 0;
    }

    int start, end, inversionCount;
    start = 0;
    end = array.size() - 1;
    inversionCount = 0;
    inversionCount = countInversionsInt(array, start, end);
    return inversionCount;
}

void
test_inversionCount()
{
    vector<int> arr = {};
    int inversionCount= 0;

    cout << "--------------------------------------------------" << endl;
    arr = {2, 3, 3, 1, 9, 5, 6};
    cout << "Input <array>" << endl;
    for (auto data:arr) {
        cout << data << " ";
    }
    cout << endl;

    cout << "Output <inversion Count> " << endl;
    inversionCount  = countInversions(arr);
    cout <<"Number of Inversion in arr: " << inversionCount << endl;
}
#endif //GNU_COUNTINVERSION_H
