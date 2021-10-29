//
// Created by kamr on 10/26/2021.
//

#ifndef GNU_LARGESTRANGE_H
#define GNU_LARGESTRANGE_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> largestRange(vector<int> array)
{
        if ((array.size() == 0) && (array.size() == 1)){
            return {};
        }

        vector<int> LargestRange;
        int LargestLen = -1;
        int CurrLen;
        int left, right;
        /* Hash is to create map of integer present in array */
        unordered_map<int, bool> hash;

        /* create hash for each integer, hash says the integer is visisted */
        for (int &data : array) {
            hash[data] = true;
        }

        for (int &data:array) {
                if (!hash[data]) {
                    continue;
                }

                /* we found number that is present in array */
                CurrLen = 1;
                hash[data] = false;
                left = data - 1;
                right = data + 1;

                /* count the elements to its left */
                while (hash.find(left) != hash.end()) {
                    hash[left] = false;
                    left = left - 1;
                    CurrLen = CurrLen + 1;
                }

                /* count the elements to its right */
                while (hash.find(right) != hash.end()) {
                    hash[right] = false;
                    right = right + 1;
                    CurrLen = CurrLen + 1;
                }

                if (CurrLen > LargestLen) {
                    LargestLen = CurrLen;
                    LargestRange = {left + 1, right - 1};
                }
        }
        return LargestRange;
}

void test_LargestRange()
{
    vector <int> arr1= {1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6};
    vector <int> arr2 = {1};
    vector <int> arr3 = {1, 2};
    vector <int> arr4 = {4, 2, 1, 3};
    vector <int> arr5 = {4, 2, 1, 3, 6};
    vector <int> arr6 = {19, -1, 18, 17, 2, 10, 3, 12, 5, 16, 4, 11, 8, 7, 6, 15, 12, 12, 2, 1, 6, 13, 14};

    vector<int> res;

    PrintArray(arr1);
    res = largestRange(arr1);
    PrintArray(res);

    PrintArray(arr2);
    res = largestRange(arr2);
    PrintArray(res);

    PrintArray(arr3);
    res = largestRange(arr3);
    PrintArray(res);

    PrintArray(arr4);
    res = largestRange(arr4);
    PrintArray(res);

    PrintArray(arr5);
    res = largestRange(arr5);
    PrintArray(res);



};

#endif //GNU_LARGESTRANGE_H
