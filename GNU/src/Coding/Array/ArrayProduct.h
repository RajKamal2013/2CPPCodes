//
// Created by kamr on 10/18/2021.
//

#ifndef GNU_ARRAYPRODUCT_H
#define GNU_ARRAYPRODUCT_H

#include<iostream>
#include<vector>
using namespace std;

int
LIdx(int idx) {
    return (idx - 1);
}

int
RIdx(int idx) {
    return (idx + 1);
}

int Left(const vector<int> LeftP, int idx) {
    if (idx < 0) {
        return 1;
    } else {
       // cout << "Left:" << idx << " Value:" << LeftP[idx - 1] <<  endl;
        return LeftP[idx];
    }
}

int Right(const vector<int> RightP, int idx, vector<int> arr) {
    if (idx >= arr.size()) {
        return 1;
    } else {
        return RightP[idx];
    }
}

vector<int>
ArrayProduct(vector<int> array)
{
    vector<int> res;
    vector<int> LeftP;
    vector<int> RightP(array.size());
    int product;

    if (array.size() == 0) {
        return {};
    }

    if (array.size() == 1) {
        return {};
    }

    if (array.size() == 2) {
        res.push_back(array[1]);
        res.push_back(array[0]);
        return res;
    }
    product = 1;
    for (int idx = 0; idx < array.size(); idx++) {
        product = array[idx] * product;
        LeftP.push_back(product);
    }

    product = 1;
    for (int idx = (array.size()-1); idx >=0 ; idx--) {
        product = array[idx] * product;
        RightP[idx] = product;
    }

    res.clear();
    product  = 1;
    int left;
    int right;
    for (int idx = 0; idx < array.size(); idx++) {
        left = Left(LeftP, LIdx(idx));
        right = Right(RightP, RIdx(idx), array);
        product =  left * right;
        res.push_back(product);
    }
    return res;
}

/*
void PrintArray(vector<int> a1) {
    cout << "{";
    for (auto &data:a1) {
        cout << data << " ";
    }
    cout << "{" << endl;
}
 */
void test_ArrayProduct()
{
    vector<int> a1{5, 1, 4, 2 };
    vector<int> a2{1, 2};

    vector<int> res;
    cout<< "Input :";
    PrintArray(a1);
    res = ArrayProduct(a1);
    cout<< "Output:";
    PrintArray(res);
}

#endif //GNU_ARRAYPRODUCT_H
