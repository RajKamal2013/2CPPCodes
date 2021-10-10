//
// Created by kamr on 10/4/2021.
//

#ifndef GNU_VALIDATESUBSEQUENCE_H
#define GNU_VALIDATESUBSEQUENCE_H
#include <iostream>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    int idx1, idx2;


    idx1 = idx2 = 0;
    while (idx1 < array.size()) {
        if (array[idx1] == sequence[idx2]) {
            idx2++;
            if (idx2 == sequence.size()) {
                return true;
            }
        }
        idx1++;
    }
    return false;
}

void test_isValidSubsequence() {
    vector<int> array{5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> seq{1, 6, -1, 10};
    bool ret = isValidSubsequence(array, seq);
    cout << "[" << " ";
    for (auto &idx : array) {
        cout << idx << " ";
    }
    cout << "] " << endl;

    cout << "[" << " ";
    for (auto &idx : seq) {
        cout << idx<< " ";
    }
    cout << "] " << endl;
    cout<< "IsValidSubsequence:" << ret << endl;
    return;
}

#endif //GNU_VALIDATESUBSEQUENCE_H
