//
// Created by kamr on 10/4/2021.
//

#ifndef GNU_SORTEDSQUARE_H
#define GNU_SORTEDSQUARE_H


#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
    vector<int> ret;
    int n_idx, idx;

    if (array.size() == 0) {
        return {};
    }

    idx = 0;
    n_idx = -1;
    while (array[idx] < 0) {
        n_idx  = idx;
        idx++;
    }

    if (n_idx == -1) {
        for (idx = 0; idx < array.size(); idx++) {
            ret.push_back(array[idx] * array[idx]);
        }
    } else {
        int p_idx = n_idx + 1;
        int id1, id2, val1, val2;
        id1 = n_idx;
        id2 = p_idx;

        while (id1 >= 0 && id2 < array.size()) {
            val1 = array[id1] * array[id1];
            val2 = array[id2] * array[id2];
            if (val1 > val2) {
                ret.push_back(val2);
                id2++;
            } else {
                ret.push_back(val1);
                id1--;
            }
        }

        while (id1 >= 0) {
            val1 = array[id1] * array[id1];
            ret.push_back(val1);
            id1--;
        }

        while (id2 < array.size()) {
            val2 = array[id2] * array[id2];
            ret.push_back(val2);
            id2++;
        }
    }
    return ret;
}

void test_sortedSquare() {
    vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> vec2 {-9, -8, 0, 1, 5, 7, 8};
    vector<int> ret;

    ret = sortedSquaredArray(vec1);

    cout << "[ ";
    for (auto &idx: vec1) {
        cout << idx << " ";
    }
    cout <<"]" << endl;

    cout << "[ ";
    for (auto &idx: ret) {
        cout << idx << " ";
    }
    cout << "]" << endl;

    ret = sortedSquaredArray(vec2);

    cout << "[ ";
    for (auto &idx: vec2) {
        cout << idx << " ";
    }
    cout << "]" << endl;

    cout << "[ ";
    for (auto &idx: ret) {
        cout << idx << " ";
    }
    cout <<"]" << endl;
}

#endif //GNU_SORTEDSQUARE_H
