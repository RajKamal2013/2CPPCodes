//
// Created by kamr on 10/4/2021.
//

#ifndef GNU_SMALLESTDIFFERENCE_H
#define GNU_SMALLESTDIFFERENCE_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());

    int idx1 = 0;
    int idx2 = 0;
    int data1, data2;

    int minDiff = INT32_MAX;
    data1 = arrayOne[idx1];
    data2 = arrayTwo[idx2];
    int diff;

    while ((idx1 < arrayOne.size()) && (idx2 < arrayTwo.size())) {
        diff = abs(arrayOne[idx1] - arrayTwo[idx2]);
        if (minDiff > diff) {
            minDiff = diff;
            data1 = arrayOne[idx1];
            data2 = arrayTwo[idx2];
        }

        if (arrayOne[idx1] > arrayTwo[idx2]) {
            idx2++;
        } else {
            idx1++;
        }
    }

    while (idx1 < arrayOne.size()) {
        diff = abs(arrayOne[idx1] - arrayTwo[idx2-1]);
        if (minDiff > diff) {
            minDiff = diff;
            data1 = arrayOne[idx1];
            data2 = arrayTwo[idx2 -1];
        }
        idx1++;
    }

    while (idx2 < arrayTwo.size()) {
        diff = abs(arrayOne[idx1 - 1] - arrayTwo[idx2]);
        if (minDiff > diff) {
            minDiff = diff;
            data1 = arrayOne[idx1 - 1];
            data2 = arrayTwo[idx2];
        }
        idx2++;
    }

    vector<int> res;
    res.push_back(data1);
    res.push_back(data2);
    return res;
}

void test_smallestDifference() {
    vector<int> arr1{ -1, 5,  10, 20, 28, 3};
    vector<int> arr2{26, 134 , 135, 15, 17};
    vector<int> res;

    res = smallestDifference(arr1, arr2);

    for (auto &val:arr1) {
        cout << val << " " ;
    }
    cout << endl;

    for (auto &val:arr2) {
        cout << val << " ";
    }

    cout << endl;

    for (auto &val:res) {
        cout << val << " " ;
    }

    cout << endl;


    arr1 = { 10, 1000};
    arr2 = {-1441, -124, -25, 1014, 1500, 660, 410, 245, 530};

    res = smallestDifference(arr1, arr2);

    for (auto &val:arr1) {
        cout << val << " " ;
    }
    cout << endl;

    for (auto &val:arr2) {
        cout << val << " ";
    }

    cout << endl;

    for (auto &val:res) {
        cout << val << " " ;
    }

    cout << endl;


    arr1 =  {10, 1000, 9124, 2142, 59, 24, 596, 591, 124, -123 };
    arr2 = {-1441, -124, -25, 1014, 1500, 660, 410, 245, 530};

    res = smallestDifference(arr1, arr2);

    for (auto &val:arr1) {
        cout << val << " " ;
    }
    cout << endl;

    for (auto &val:arr2) {
        cout << val << " ";
    }

    cout << endl;

    for (auto &val:res) {
        cout << val << " " ;
    }

    cout << endl;

    arr1 = {10, 1000, 9124, 2142, 59, 24, 596, 591, 124, -123, 530};
    arr2={-1441, -124, -25, 1014, 1500, 660, 410, 245, 530};

    res = smallestDifference(arr1, arr2);

    for (auto &val:arr1) {
        cout << val << " " ;
    }
    cout << endl;

    for (auto &val:arr2) {
        cout << val << " ";
    }

    cout << endl;

    for (auto &val:res) {
        cout << val << " " ;
    }

    cout << endl;
}


#endif //GNU_SMALLESTDIFFERENCE_H
