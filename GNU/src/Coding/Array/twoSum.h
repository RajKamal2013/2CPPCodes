//
// Created by kamr on 10/1/2021.
//

#ifndef GNU_TWOSUM_H
#define GNU_TWOSUM_H

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    if (array.size() < 2) {
        return {};
    }

    if (array.size() == 2) {
        if ((array[0] + array[1]) == targetSum) {
            return array;
        } else {
            return {};
        }
    }

    sort(array.begin(), array.end());

    int sum = 0;
    int left, right;
    left = 0;
    right = array.size() - 1;

    while (left < right) {
        sum = array[left] + array[right];
        if (sum == targetSum) {
            vector <int> arr;
            arr.push_back(array[left]);
            arr.push_back(array[right]);
            return arr;
            break;
        } else if (sum > targetSum) {
            right = right - 1;
        } else {
            left = left + 1;
        }
    }

    return {};
}

void test_two_sum()
{
    vector<int> vec;
    vector<int>array{3, 5, -4, 8, 11, 1, -1, 6};
    vec = twoNumberSum(array, 10);
    cout << "[";
    for (const auto &idx : vec) {
        cout << idx << " ";
    }
    cout << "]" << endl;
}

#endif //GNU_TWOSUM_H
