//
// Created by kamr on 11/17/2021.
//

#ifndef GNU_SEARCHINSORTEDMATRIX_H
#define GNU_SEARCHINSORTEDMATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> mat, int target) {
    if (mat.size() == 0) {
        return {-1, -1};
    }
// get row and column size
    int rSize = mat.size();
    int cSize = mat[0].size();

// set up start and end index
    int rowEnd = rSize - 1;
    int rowStart = 0;
    int colStart = 0;
    int colEnd = cSize - 1;

// set up iterators
    int r = rowStart;
    int c = colEnd;
    bool found = false;

// output
    vector<int> outputIndices(2);

    while ((!found) && (r >= rowStart) && (r <= rowEnd) && (c >= colStart) && (c <= colEnd)) {
        if (target > mat[r][c]) { // we will go down
            r = r + 1;
        } else if (target < mat[r][c]) { // we will go left
            c = c - 1;
        } else { // we found the value
            found = true;
            outputIndices[0] = r;
            outputIndices[1] = c;
        }
    }

    if (!found) {
        outputIndices[0] = -1;
        outputIndices[1] = -1;
    }

    return outputIndices;
}

void test_searchInSortedMatrix() {
    vector<vector<int>> matrix;
    int target;
    vector<int> targetIndices = {};

    matrix = {{1, 4, 7, 12, 15, 1000},
              {2, 5, 19, 31, 32, 1001},
              {3, 8, 24, 33, 35, 1002},
              {40, 41, 42, 44, 45, 1003},
              {99, 100, 103, 106, 128, 1004 }
            };
    cout << "Input Matrix :" << endl;
    for (auto row : matrix) {
        for (auto col:row) {
            cout << setw(4) << col << " ";
        }
        cout << endl;
    }
    target = 44;
    targetIndices  = searchInSortedMatrix(matrix, target);
    cout << "Indices for target :" << target << " in matrix are :";
    for (auto idx:targetIndices) {
        cout << idx << " ";
    }
    cout << endl;


    matrix = {{1, 4, 7, 12, 15, 1000},
              {2, 5, 19, 31, 32, 1001},
              {3, 8, 24, 33, 35, 1002},
              {40, 41, 42, 44, 45, 1003},
              {99, 100, 103, 106, 128, 1004 }
    };
    cout << "Input Matrix :" << endl;
    for (auto row : matrix) {
        for (auto col:row) {
            cout << setw(4) << col << " ";
        }
        cout << endl;
    }
    target = 100;
    targetIndices  = searchInSortedMatrix(matrix, target);
    cout << "Indices for target :" << target << " in matrix are :";
    for (auto idx:targetIndices) {
        cout << idx << " ";
    }
    cout << endl;


    matrix = {{1, 4, 7, 12, 15, 1000},
              {2, 5, 19, 31, 32, 1001},
              {3, 8, 24, 33, 35, 1002},
              {40, 41, 42, 44, 45, 1003},
              {99, 100, 103, 106, 128, 1004 }
    };
    cout << "Input Matrix :" << endl;
    for (auto row : matrix) {
        for (auto col:row) {
            cout << setw(4) << col << " ";
        }
        cout << endl;
    }
    target = 101;
    targetIndices  = searchInSortedMatrix(matrix, target);
    cout << "Indices for target :" << target << " in matrix are :";
    for (auto idx:targetIndices) {
        cout << idx << " ";
    }
    cout << endl;
}
#endif //GNU_SEARCHINSORTEDMATRIX_H
