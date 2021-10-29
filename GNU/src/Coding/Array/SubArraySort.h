//
// Created by kamr on 10/22/2021.
//

#ifndef GNU_SUBARRAYSORT_H
#define GNU_SUBARRAYSORT_H

#include <iostream>
#include <vector>
using namespace std;

vector<int>
subarraySort(vector<int> array)
{
    int idx;
    bool test = true;

    /*****************************************Input ************************************************/

    if (test) {
        cout << "Input: ";
        cout << "[";
        for (auto &data:array) {
            cout << data << " ";
        }
        cout << "]" << endl;
    }

    /****************************************** Find the start index *******************************/
    int S1, S2, prev;
    prev = array[0];
    S1 = S2= -1;

    for (idx = 1; idx < array.size(); idx++) {
        if (array[idx] < prev) {
            S2 = idx;
            break;
        }
        prev = array[idx];
    }
   /* Find greater number than S2 */
    if (S2 != -1) {
        for (idx = 0; idx < S2; idx++) {
            if (array[idx] > array[S2]) {
                S1 = idx;
                break;
            }
        }
    }

    int min;
    if (S1 != -1) {
        min = array[S1];
        for (idx = S1 + 1; idx < array.size() - 1; idx++) {
            if (min > array[idx]) {
                min = array[idx];
            }
        }
        if (min != array[S1]) {
            for (idx = 0; idx <= S1; idx++) {
                if (array[idx] > min) {
                    S1 = idx;
                    break;
                }
            }
        }
    }

    if (test) {
        cout << "Starting index :" <<  S1 << endl;
    }


    /************************************** Find the End Index *************************************/
    int E1, E2;
    E1 = E2 = -1;
    prev = array[array.size() -1];
    /* Find number such that prev is smaller than current */
    for (idx = array.size()-1; idx >= 0; idx--) {
        if (prev < array[idx]) {
            E2 = idx;
            break;
        }
        prev = array[idx];
    }

    if (E2 != -1) {
        /* find number E1 from last such that , Array[E1] is smaller than array[E2] */
        for (idx = E2 + 1; idx < array.size(); idx++) {
            if (array[idx] < array[E2]) {
                E1 = idx;
            }
        }
    }

    int max;
    if (E1 != -1) {
        max = array[E1];
        for (idx = E1 - 1; idx >= 0; idx--) {
            if (max > array[idx]) {
                max = array[idx];
            }
        }
        if (max != array[E1]) {
            for (idx = array.size() - 1; idx >= E1; idx--) {
                if (array[idx] < max) {
                    E1 = idx;
                    break;
                }
            }
        }
    }


    if (test) {
        cout << "Ending index :" <<  E1 << endl;
    }



    vector<int> subarray;
    subarray.push_back(S1);
    subarray.push_back(E1);

    /*****************************************Output************************************************/


    if (test) {
        cout << "Output: ";
        cout << "[";
        for (auto &data:subarray) {
            cout << data << " ";
        }
        cout << "]" << endl;
    }


    return subarray;
}

void test_SubArraySort()
{
    bool test = false;
    vector<int> arr1 {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    vector<int> arr2 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> arr3 {1, 2, 4, 7, 10, 11, 7, 12, 7, 7, 16, 18, 19};
    vector<int> arr4 {2, 1};
    vector<int> arr5 {2, 1, 1};


    vector<int> subarray;


    subarray = subarraySort(arr1);

    if (test) {
        cout << "[";
        for (auto &data : subarray) {
            cout << data << " ";
        }
        cout << "]" << endl;
    }

    subarray = subarraySort(arr2);

    if (test) {
        cout << "[";
        for (auto &data : subarray) {
            cout << data << " ";
        }
        cout << "]" << endl;
    }


    subarray = subarraySort(arr3);

    if (test) {
        cout << "[";
        for (auto &data : subarray) {
            cout << data << " ";
        }
        cout << "]" << endl;
    }


    subarray = subarraySort(arr4);

    if (test) {
        cout << "[";
        for (auto &data : subarray) {
            cout << data << " ";
        }
        cout << "]" << endl;
    }
    subarray = subarraySort(arr5);

    if (test) {
        cout << "[";
        for (auto &data : subarray) {
            cout << data << " ";
        }
        cout << "]" << endl;
    }

}

#endif //GNU_SUBARRAYSORT_H
