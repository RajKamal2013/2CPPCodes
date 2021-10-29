//
// Created by kamr on 10/26/2021.
//

#ifndef GNU_ZIGZAGTRAVERSEMATRIX_H
#define GNU_ZIGZAGTRAVERSEMATRIX_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void
PrintMatrix(vector<vector<int>> mat) {

    int M, N;
    M = mat.size();
    N = mat[0].size();
    cout << "ROW:" << M << " COLUMN: " <<N << endl;
    cout << "[" << endl;
    for (auto &row: mat) {
        cout << " {";
        for (auto &col:row) {
             cout << col << " ";
        }
        cout << " }" << endl;
    }
    cout << "]" << endl;
}

vector<int>
zigzagTraverse(vector<vector<int>> mat) {

    bool test = false;
    /* Globals */
    int DOWN   = 0;
    int UDiag  = 1;
    int RIGHT  = 2;
    int DDiag  = 3;

    int count= 0;
    int currPos = 0;
    int M, N, TotalElement;
    int row, column;
    int i, j;

    /* row size */
    M = mat.size();
    /* Column Size */
    N = mat[0].size();
    /* Total number of elements in matrix */
    TotalElement = M * N;

    row = column = 0;
    /* result */
    vector<int> res;

    /*  Row vector */
    if (M == 1) {
        j = 0;
        while (j < N) {
            res.push_back(mat[0][j]);
            j = j + 1;
        }
        return res;
    }

    /* Column Vector */
    if (N == 1) {
        i = 0;
        while (i < M) {
            res.push_back(mat[i][0]);
            i = i + 1;
        }
        return res;
    }

    i = j = 0;
    if (test) {
        cout << "Start:" << i << " " << j << endl;
    }

    /* Zig Zag */
    res.push_back(mat[i][j]);
    count = count + 1;
    while ((count != TotalElement))
    {
        if (test) {
            cout << "Count:" << count << " i:" << i << "j:" << j << " CurPos:" << currPos << endl;
            PrintArray(res);
        }
        if (currPos == DOWN) {
            if (i + 1 >= M) {
                if (j + 1 < N) {
                    j = j + 1;
                    if (test) {
                        cout << "Down1:" << i << " " << j << endl;
                    }
                    res.push_back(mat[i][j]);
                    count++;
                }
                currPos = UDiag;
            } else {
                i  =  i + 1;
                if (test) {
                    cout << "Down2:" << i << " " << j << endl;
                }
                res.push_back(mat[i][j]);
                count++;
                currPos = UDiag;
            }
        } else if (currPos == UDiag) {
            while (((i - 1) >= 0) && (j + 1 < N)) {
                i = i - 1;
                j = j  + 1;
                if (test) {
                    cout << "Udiag:" << i << " " << j << endl;
                }
                res.push_back(mat[i][j]);
                count++;
            }
            currPos = RIGHT;
        } else if (currPos == RIGHT) {
            if (j + 1 >= N) {
                if (i + 1 < M) {
                    i = i + 1;
                    if (test) {
                        cout << "RIGHT1:" << i << " " << j << endl;
                    }
                    res.push_back(mat[i][j]);
                    count++;
                }
                currPos = DDiag;
            } else {
                j = j + 1;
                if (test) {
                    cout << "RIGHT2:" << i << " " << j << endl;
                }
                res.push_back(mat[i][j]);
                count++;
                currPos = DDiag;
            }
        } else if (currPos == DDiag) {
            while (((i + 1) < M) && ((j - 1) >= 0)) {
                i = i  + 1;
                j = j - 1;
                if (test) {
                    cout << "DDiag:" << i << " " << j << endl;
                }
                res.push_back(mat[i][j]);
                count++;
            }
            currPos = DOWN;
        } else {
            break;
        }
    }

    return res;

}

void test_zigzagTravers() {
    vector<vector<int>> mat1 =  {
                                 {1, 3, 4, 10},
                                 {2, 5, 9, 11},
                                 {6, 8, 12, 15},
                                 {7, 13, 14, 16}
                                };
    vector<int> res = {};

    PrintMatrix(mat1);
    res = zigzagTraverse(mat1);
    PrintArray(res);
}
#endif //GNU_ZIGZAGTRAVERSEMATRIX_H
