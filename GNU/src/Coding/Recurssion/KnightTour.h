//
// Created by kamr on 10/29/2021.
//

#ifndef GNU_KNIGHTTOUR_H
#define GNU_KNIGHTTOUR_H
#include <iostream>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;
/*
 * There are 8 possible move for a knight in chess from a position.
 * (x+2, y+1), (x+2, y-1), (x-2, y+1), (x-2, y -1),
 * (x+1, y+2), (x+1, y-2), (x-1, y+2), (x-1), y-2)
 *
 * (2, 1), (2, -1), (-2, 1), (-2, -1)
 * (1, 2), (1, -2), (-1, 2), (-1, -2)
 *
 * (2, 2, -2, -2, 1, 1, -1, -1) -> X
 * (1, -1, 1, -1, 2, -2, 2, -2) -> Y
 */


bool isSafe(int x, int y, int M, int N, int  **tour) {
    return ((x >= 0) && (x < N) && (y >= 0) && (y < N) && (tour[x][y] == -1));
}

void printSolution(int **tour, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << " " << setw(2) << tour[i][j] << " ";
        }
        cout << endl;
    }
}

bool findPath(int x, int y, int count, int M, int N, int **tour, int moveX[8], int moveY[8]) {
    if (count == N * N) {
        return true;
    }

    int X, Y;
    for (int k = 0; k < 8; k++) {
        X = x + moveX[k];
        Y = y + moveY[k];
        if (isSafe(X, Y, M, N, tour)) {
            tour[X][Y] = count;
            if (findPath(X, Y, count + 1, M, N, tour, moveX, moveY)) {
                return true;
            } else {
               // backtracking
                tour[X][Y] = -1;
            }
        }
    }
    return 0;
}

void KnightTour(int K, int xPos, int yPos) {
    int **tour;
    tour = new int*[K];
    for (int i =0; i < K; i++) {
        tour[i] = new int[K];
    }
    // initialize
    for (int x = 0; x < K; x++) {
        for (int y = 0; y < K; y++) {
            tour[x][y] = -1;
        }
    }

    int moveX[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int moveY[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    int count  = 1;

    tour[xPos][yPos] = count;

    if (findPath(xPos, yPos, count, K, K, tour, moveX, moveY)) {
        printSolution(tour, K, K);
    } else {
        cout << "No path exist" << endl;
    }
}

void assign(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            arr[i][j] = i + j;
        }
    }
}

void test_KnightTour() {

    KnightTour(6, 0, 0);


    /*
    int M, N;
    M = N = 8;
    int **arr;
    arr = new int*[M];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[N];
    }


     int K = 8;
    int test[K][K];
    // initialize
    for (int x = 0; x < K; x++) {
        for (int y = 0; y < K; y++) {
            test[x][y] = -1;
        }
    }
     assign(arr, M, N);
     printSolution(test, M, N);
     */
}

#endif //GNU_KNIGHTTOUR_H
