//
// Created by kamr on 11/10/2021.
//

#ifndef GNU_MINCOINCHANGE_H
#define GNU_MINCOINCHANGE_H

using namespace std;

#include <iostream>
#include <limits>
#include <vector>
#include <climits>

class CoinChange {

public:

    int countChangeHelper(const vector<int> &denominations, int total, int currentIdx) {
        if (total < 0) {
            return INT_MAX;
        }

        if (total == 0) {
            return 0;
        }

        if ((denominations.empty()) || (currentIdx > (denominations.size() -1))) {
            return INT_MAX;
        }
        int denominationsInc, denominationExl;
        denominationsInc = INT_MAX;
        if (denominations[currentIdx] <= total) {
            denominationsInc = countChangeHelper(denominations, total - denominations[currentIdx], currentIdx);
            if (denominationsInc != INT_MAX) {
                denominationsInc = denominationsInc + 1;
            }
        }
        denominationExl = countChangeHelper(denominations, total, currentIdx + 1);
        int count = min(denominationExl, denominationsInc);

        return count;
    }

    int countChange(const vector<int> &denominations, int total) {
        if (total <= 0) {
            return -1;
        }
        if (denominations.size() == 0) {
            return -1;
        }

        if (denominations.size() == 1) {
            int quot = total/denominations[0];
            int rem = total % denominations[0];
            if (rem != 0) {
                quot = quot + 1;
            }
            cout << "Quot" << quot << endl;
            return quot;
        }
        int currentIdx = 0;

        int minWays = INT_MAX;
        minWays = countChangeHelper(denominations, total, currentIdx);
        if (minWays == INT_MAX) {
            return -1;
        }
        return minWays;
    }
};

void
test_minCoinChange() {
    CoinChange *cc = new CoinChange();
    vector<int> denominations = {1, 2, 3};
    cout << cc->countChange(denominations, 5) << endl;
    cout << cc->countChange(denominations, 11) << endl;
    cout << cc->countChange(denominations, 7) << endl;
    denominations = vector<int>{3, 5};
    cout << cc->countChange(denominations, 7) << endl;

    delete cc;
}

#endif //GNU_MINCOINCHANGE_H
