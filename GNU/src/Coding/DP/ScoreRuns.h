//
// Created by kamr on 11/10/2021.
//

#ifndef GNU_SCORERUNS_H
#define GNU_SCORERUNS_H

#include <vector>
using namespace std;

int
gameScoringHelper(int n, vector<int> &result) {

    if (n < 0) {
        return 0;
    }

    if (result[n] > 0) {
        return result[n];
    }

    result[n] = gameScoringHelper(n-1, result) + gameScoringHelper(n-2, result) + gameScoringHelper(n-4, result);
    return result[n];
}

int gameScoring(int n) {
    vector<int> result = {n+1, -1};
    result[0] = 1;

    if (n <= 0) {
        return 0;
    }

    int res = gameScoringHelper(n, result);
    return (res);
}

void
test_gameScoring() {
    int n = 5;
    cout << "Number of ways score " << n <<   " can be reached = " << gameScoring(5); //10
}

#endif //GNU_SCORERUNS_H
