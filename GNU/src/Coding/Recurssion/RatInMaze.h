//
// Created by kamr on 11/2/2021.
//

#ifndef GNU_RATINMAZE_H
#define GNU_RATINMAZE_H

/*
 * Maze is N*N Binary matrix.
 * Maze[x][y] == 0 -> dead cell
 * Maze[x][y] == 1 -> Valid cell
 * Source -> [0][0]
 * Destination -> [N-1][N-1]
 * Rat can move forward or down -> (x+1, y) or (x, y+1)
 * Find path, so that rat can reach from source to destination
 *
 *
 */

/* Not working */


bool
isSafeMaze(int x, int y, int M, int N, int **maze) {
    bool ret = (x >= 0) && (x < M) && (y >= 0) && (y < N) && (maze[x][y] == 1);
    return ret;
}

void
PrintSolution(int **Solution, int M, int N) {
    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            cout << setw(2) << Solution[row][col];
        }
        cout << endl;
    }
}

/*
 * Idea is visit every possible moves and check if we reach the destination
 */
bool
solveUtil(int X, int Y, int M, int N, int **maze, int **Solution) {
    bool FoundSolution  = false;
    /* Did we just reach the destination */
    FoundSolution = ((X == M -1) && (Y == N - 1) && (maze[X][Y] == 1) && (Solution[X][Y] == 1));
    if (FoundSolution) {
        return  true;
    }

    /* Is it safe to visit  - valid cell */
    if (isSafeMaze(X, Y, M, N, maze)) {
        /* Already visited , it will lead to cycle ow */
        if (Solution[X][Y] == 1) {
            return false;
        }
        /* Marked visited */
        Solution[X][Y] = 1;

        /* Move forward */
        if (solveUtil(X, Y + 1, M, N, maze, Solution)) {
            return true;
        }

        /* Move Down */
        if (solveUtil(X + 1, Y, M, N, maze, Solution)) {
            return true;
        }

        /* We could not find solution so unset the visited */
        Solution[X][Y] = 0;
        return false;
    }

    /* We hit the dead cell */
    return false;
}

void
solve(int X, int Y, int M, int N, int **maze) {
    int **Solution;
    Solution  = new int*[M];
    for (int i =0; i < M; i++) {
        Solution[i] = new int[N];
    }
    // initialize
    for (int x = 0; x < M; x++) {
        for (int y = 0; y < N; y++) {
            Solution[x][y] = 0;
        }
    }

    bool FoundPath = solveUtil(X, Y, M, N, maze, Solution);
    if (FoundPath) {
        cout << "We Found Solution " << endl;
        PrintSolution(Solution, M, N);
    } else {
        cout << "We could not Found Solution " << endl;
     }
    return;
 }

 void
 RatInAMaze(int M, int N, int** Maze) {
     solve(0, 0, M, N, Maze);

 }

 void
 test_RatInMaze() {
     int **Maze;
     int M, N;
     M = 4;
     N = 4;
     Maze  = new int*[M];
     for (int i =0; i < M; i++) {
         Maze[i] = new int[N];
     }
     // initialize
     for (int x = 0; x < M; x++) {
         for (int y = 0; y < N; y++) {
             Maze[x][y] = 0;
         }
     }

     Maze[0][0] = 1;
     Maze[1][0] = 1;
     Maze[3][0] = 1;
     Maze[1][1] = 1;
     Maze[1][3] = 1;
     Maze[2][1] = 1;
     Maze[3][0] = 1;
     Maze[3][1] = 1;
     Maze[3][2] = 1;
     Maze[3][3] = 1;

     RatInAMaze(4, 4, Maze);

 }

#endif //GNU_RATINMAZE_H
