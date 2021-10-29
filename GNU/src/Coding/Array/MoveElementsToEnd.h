//
// Created by kamr on 10/4/2021.
//

#ifndef GNU_MOVEELEMENTSTOEND_H
#define GNU_MOVEELEMENTSTOEND_H

#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
    if (array.size() == 0) {
        return {};
    }
    int left, right, val, temp;

    right = array.size() - 1;
    left = 0;
    val = toMove;

    while (array[right] == val) {
        right = right - 1;
    }

    while (left < right) {
        if (array[left]  == val) {
            temp = array[right];
            array[right] = array[left];
            array[left] = temp;
            while (array[right] == val) {
                right = right - 1;
            }
        }
        left = left + 1;
    }
    return array;
}

void test_moveElementsToEnd()
{
    vector<int> arr{2,1,2,2,2,3,4,2};
    int dataToMove  = 2;

    vector<int> res;
    res = moveElementToEnd(arr, dataToMove);

    for (auto &data : arr) {
        cout << data << " ";
    }
    cout << endl;

    for (auto &data : res) {
        cout << data << " ";
    }
    cout << endl;


    arr = {5, 1, 2, 5, 5, 3, 4, 6, 7, 5, 8, 9, 10, 11, 5, 5, 12};
    dataToMove = 5;
    res = moveElementToEnd(arr, dataToMove);

    for (auto &data : arr) {
        cout << data << " ";
    }
    cout << endl;

    for (auto &data : res) {
        cout << data << " ";
    }
    cout << endl;

}

#endif //GNU_MOVEELEMENTSTOEND_H
