//
// Created by kamr on 10/11/2021.
//

#ifndef GNU_SPIRALARRAYPRINT_H
#define GNU_SPIRALARRAYPRINT_H

#include<iostream>
using namespace std;

//*------ Good Question *-------//


vector<int> spiralTraverse(vector<vector<int>> mat) {
    int M = mat.size();
    int N = mat[0].size();
    vector<int> res;
    int spiral[4] = {0, 1, 2, 3};
    bool isDone = false;
    int idx, column_start, column_end, row_start, row_end, spiral_idx;

   // cout << "SpiralTraverse" << endl;
   // cout << "M :" << M << " N: " << N << endl;

    if ((M == 1) && (N == 1)) {
        res.push_back(mat[0][0]);
        isDone = true;
      //  cout << "M :" << M << "N: " << N << endl;
        return res;
    }

    if (M == 1) {
        for (idx = 0; idx < N; idx++) {
            res.push_back(mat[0][idx]);
            isDone =true;
        }
      //  cout << "M :" << M << "N: " << N << endl;
        return res;
    }

    if (N == 1) {
        for (idx = 0; idx < M; idx++) {
            res.push_back(mat[idx][0]);
            isDone = true;
        }
       // cout << "M :" << M << "N: " << N << endl;
        return res;
    }

    column_start = 0;
    column_end = N-1;
    row_start = 0;
    row_end = M-1;
    spiral_idx = 0;

    /*
    cout <<"{";
    for (int i = 0; i < M; i++) {
       cout << "{";
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
     */
    while (!isDone) {
        for (spiral_idx = 0; spiral_idx < 4; spiral_idx++) {
            if (spiral_idx == 0) {
                //cout << " spiral idx " << spiral_idx << "- " << row_start << " " << row_end << " " << column_start << " "<< column_end << endl;
                for (idx = column_start; idx <= column_end; idx++) {
                    res.push_back(mat[row_start][idx]);
                }
                row_start = row_start + 1;
                if (row_start > row_end) {
                    isDone = true;
                    break;
                }
            } else if (spiral_idx == 1) {
                //cout << " spiral idx " << spiral_idx << "- " << row_start << " " << row_end << " " << column_start << " "<< column_end << endl;
                for (idx = row_start; idx <= row_end; idx++) {
                   // cout << mat[idx][column_end] << " ";
                    res.push_back(mat[idx][column_end]);
                }
                column_end = column_end - 1;
                if (column_start > column_end) {
                    isDone = true;
                    break;
                }
            } else if (spiral_idx == 2) {
              //  cout << " spiral idx " << spiral_idx << "- " << row_start << " " << row_end << " " << column_start << " " << column_end << endl;
                for (idx = column_end; idx >= column_start; idx--) {
                    res.push_back(mat[row_end][idx]);
                }
                row_end = row_end - 1;
                if (row_start > row_end) {
                    isDone = true;
                    break;
                }
            } else if (spiral_idx == 3) {
                //cout << " spiral idx " << spiral_idx << "- " << row_start << " " << row_end << " " << column_start << " " << column_end << endl;
                for (idx = row_end; idx >= row_start; idx--) {
                    res.push_back(mat[idx][column_start]);
                }
                column_start = column_start + 1;
                if (column_start > column_end) {
                    isDone = true;
                    break;
                }
            } else {
                //cout << "in else" << endl;
            }
        }
        if ((row_start == row_end) && (column_start == column_end)) {
            res.push_back(mat[row_start][column_start]);
            isDone = true;
        } else if ((column_start > column_end) || (row_start > row_end)) {
            isDone = true;
        } else {
           // cout << "Continue " << endl;
            continue;
        }
    }

    if (isDone) {
       // cout << "M :" << M << "N: " << N << endl;
        return res;
    } else {
      //  cout << "M :" << M << "N: " << N << endl;
        return {};
    }
}

void test_spiralTraverse()
{
    int M, N;
    vector<vector<int>> array0 = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};

    vector<vector<int>> array1 = {{1, 2, 3} ,{8, 9, 4}, {7, 6, 5}};
    vector<vector<int>> array2 = {{1, 2, 3}};
    vector<vector<int>> array3 = {{1}, {2},{3}};
    vector<vector<int>> array4 = {{1, 2}, {6, 3}, {5, 4}};
    vector<vector<int>> array5 = {{1, 2, 3},{6, 5, 4}};
    vector<vector<int>> array6 = {{1, 2}, {4, 3}};

    vector<vector<int>> array7 = {{1, 2, 3, 4}, {10, 11, 12, 5}, {9, 8, 7, 6}};
    vector<vector<int>> array8 = {{1, 2, 3},{12, 13, 4}, {11, 14, 5}, {10, 15, 16} ,{9, 8, 7}};

    vector<int>res;


    M = array7.size();
    N = array7[0].size();
    cout <<"{";
    for (int i = 0; i < M; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            cout << array7[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
    res = spiralTraverse(array7);
    for (auto &idx:res) {
        cout << idx << " ";
    }
    cout << endl;


    M = array8.size();
    N = array8[0].size();
    cout <<"{";
    for (int i = 0; i < M; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            cout << array8[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
    res = spiralTraverse(array8);
    for (auto &idx:res) {
        cout << idx << " ";
    }
    cout << endl;

    cout <<"------------------------------------------------------" << endl;
    M = array0.size();
    N = array0[0].size();
    cout <<"{";
    for (int i = 0; i < M; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            cout << array0[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
    res = spiralTraverse(array0);
    for (auto &idx:res) {
        cout << idx << " ";
    }
    cout << endl;



    M = array0.size();
    N = array0[0].size();
    cout <<"{";
    for (int i = 0; i < M; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            cout << array0[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
    res = spiralTraverse(array0);
    for (auto &idx:res) {
        cout << idx << " ";
    }
    cout << endl;


    M = array1.size();
    N = array1[0].size();
    cout <<"{";
    for (int i = 0; i < M; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            cout << array1[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
    res = spiralTraverse(array1);
    for (auto &idx:res) {
        cout << idx << " ";
    }
    cout << endl;


    M = array2.size();
    N = array2[0].size();
    cout <<"{";
    for (int i = 0; i < M; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            cout << array2[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
    res = spiralTraverse(array2);
    for (auto &idx:res) {
        cout << idx << " ";
    }
    cout << endl;


    M = array3.size();
    N = array3[0].size();
    cout <<"{";
    for (int i = 0; i < M; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            cout << array3[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
    res = spiralTraverse(array3);
    for (auto &idx:res) {
        cout << idx << " ";
    }
    cout << endl;


    M = array4.size();
    N = array4[0].size();
    cout <<"{";
    for (int i = 0; i < M; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            cout << array4[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
    res = spiralTraverse(array4);
    for (auto &idx:res) {
        cout << idx << " ";
    }
    cout << endl;


    M = array5.size();
    N = array5[0].size();
    cout <<"{";
    for (int i = 0; i < M; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            cout << array5[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
    res = spiralTraverse(array5);
    for (auto &idx:res) {
        cout << idx << " ";
    }
    cout << endl;

    M = array6.size();
    N = array6[0].size();
    cout <<"{";
    for (int i = 0; i < M; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            cout << array6[i][j] << " ";
        }
        cout <<"}";
    }
    cout <<"}";
    cout << endl;
    res = spiralTraverse(array6);
    for (auto &idx:res) {
        cout << idx << " ";
    }
    cout << endl;

}


#endif //GNU_SPIRALARRAYPRINT_H
