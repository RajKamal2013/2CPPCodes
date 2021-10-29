//
// Created by kamr on 9/30/2021.
//

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    vector<vector<int>> arr;
    int sum = targetSum;
    int left, right;
    int twoSum = 0;

    if (array.size() < 2) {
        return {};
    }

    if (array.size() == 3) {
        if ((array[0] + array[1] + array[2]) == targetSum) {
            arr.push_back(array);
            return arr;
        } else {
            return {};
        }
    }
    sort(array.begin(), array.end());

    for (int idx = 0; idx < array.size(); idx++) {
        sum = targetSum - array[idx];
        left = idx + 1;
        right = array.size() - 1;

        while (left < right) {
            twoSum = array[left] + array[right];
            if (twoSum == sum) {
                vector<int> vec;
                vec.push_back(array[idx]);
                vec.push_back(array[left]);
                vec.push_back(array[right]);
                arr.push_back(vec);
                /*
                for (const auto& i: vec)
                    std::cout << i << ' ' ;
                cout << endl;
                 */
                left = left + 1;
            } else if (twoSum > sum) {
                right = right - 1;
            } else {
                left = left + 1;
            }
        }
    }

    /*
    cout << "size of array " << arr.size() << endl;
    cout<<"Inside Test Three Sum" << endl;

    for (const auto &idx : arr) {
        cout << "[ " ;
        for (const auto &i : idx) {
            cout << i << " " ;
        }
        cout << "]" << endl;
    }
     */
    return arr;
}

void test_threeSum() {
    vector<int> vec {12, 3, 1, 2, -6, 5, -8, 6};
    int sum = 0;
    cout<<"Inside Test Three Sum" << endl;
    vector<vector<int>> arr;
    vector<int> data;
    arr = threeNumberSum(vec, sum);

    cout << "[";
    for (const auto &idx : arr) {
        cout << "[ " ;
        for (const auto &i : idx) {
            cout << i << " " ;
        }
        cout << "]" << "";
    }

    cout << "]" << endl;
}

