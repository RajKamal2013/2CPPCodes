//
// Created by kamr on 11/13/2021.
//

#ifndef GNU_SPIRALARRAYPRINT2_H
#define GNU_SPIRALARRAYPRINT2_H

#include <vector>
using namespace  std;
/*
 * Given a 2D array (matrix) inputMatrix of integers, create a
 * function spiralCopy that copies inputMatrix’s values into a
 * 1D array in a spiral order, clockwise. Your function then should
 * return that array. Analyze the time and space complexities of your solution.
 * Example:
 * input:  inputMatrix  = [ [1,    2,   3,  4,    5],
 *                          [6,    7,   8,  9,   10],
 *                          [11,  12,  13,  14,  15],
 *                          [16,  17,  18,  19,  20] ]
 *
 * output: [1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12]
 */

vector<int> spiralCopy( vector<vector<int> > matrix)
{
    int rowCount = matrix.size();
    int colCount = matrix[0].size();
    vector<int> array = {};
    int colStart, rowStart, rowEnd, colEnd;
    int totalElement = rowCount * colCount;
    enum move { Right, Down, Left, Up };
    int count = 0;
    move nextPos;
    int r, c;

    colStart = rowStart = 0;
    colEnd = colCount - 1;
    rowEnd = rowCount - 1;
    nextPos = Right;
    while (count != totalElement) {
        switch (nextPos) {
            case Right:
                r = rowStart;
                //place all row in the array
                for (c = colStart; c <= colEnd; c++) {
                    array.push_back(matrix[r][c]);
                    count = count + 1;
                }
                nextPos = Down;
                rowStart = rowStart + 1;
                break;
            case Down:
                // all the column in array down wise
                c = colEnd;
                for (r = rowStart; r <= rowEnd; r++) {
                    array.push_back(matrix[r][c]);
                    count = count + 1;
                }
                nextPos = Left;
                colEnd = colEnd - 1;
                break;
            case Left:
                // move left in row wise
                r = rowEnd;
                for (c = colEnd; c >= colStart; c--) {
                    array.push_back(matrix[r][c]);
                    count = count + 1;
                }
                nextPos = Up;
                rowEnd  = rowEnd - 1;
                break;
            case Up:
                //move up row wise
                c = colStart;
                for (r = rowEnd; r >= rowStart; r--) {
                    array.push_back(matrix[r][c]);
                    count = count + 1;
                }
                nextPos = Right;
                colStart = colStart + 1;
                break;
        }
    }
    return array;
}

void printMatrix(vector<vector<int> > matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    cout << "Row :" << row << "Column:" << col << endl;
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
}

void test_spiralCopy() {
    vector<vector<int> > matrix = {{}};
    vector<int> arr = {};
    matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
    cout << "Input Matix : " << endl;
    printMatrix(matrix);
    arr = spiralCopy(matrix);
    cout << "Output of matrix in array" << endl;
    for (auto data:arr) {
        cout << data << " ";
    }
    cout << endl;
}


#endif //GNU_SPIRALARRAYPRINT2_H
