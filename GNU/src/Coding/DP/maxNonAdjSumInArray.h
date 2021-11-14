//
// Created by kamr on 11/14/2021.
//

#ifndef GNU_MAXNONADJSUMINARRAY_H
#define GNU_MAXNONADJSUMINARRAY_H
#include <vector>
using namespace std;

int
maxSubsetSumNoAdjacent(vector<int> array) {
    vector<int> maxNonAdjSumArray(array.size(), -1);
    // Empty array  case
    if (array.size() == 0) {
        return 0;
    }

    // base case
    if (array.size() == 1) {
        return array[0];
    }

    maxNonAdjSumArray[0] = array[0];

    for (int idx = 0; idx  < array.size(); idx++) {
        if ((idx - 2) >= 0) { // idx -> 2 to array.size()
            maxNonAdjSumArray[idx] = max(maxNonAdjSumArray[idx - 1], maxNonAdjSumArray[idx - 2]  + array[idx]);
        } else { // if idx = 1
            maxNonAdjSumArray[idx] = max(maxNonAdjSumArray[idx - 1], array[idx]);
        }
    }

    return maxNonAdjSumArray[array.size() - 1];
}

void test_maxSumNoAdjacent() {
    vector<int> array = {};
    int maxSum = 0;

    array = {75, 105, 120, 75, 90, 135};
    cout << "Input Array " << endl;
    for (auto data:array) {
        cout << data << " ";
    }
    cout << endl;
    maxSum = maxSubsetSumNoAdjacent(array);
    cout << "Output < maximum non adjacent sum>" << endl;
    cout << "Maximum Non Adjacent Sum in array : " << maxSum << endl;
}

#endif //GNU_MAXNONADJSUMINARRAY_H
