//
// Created by kamr on 11/10/2021.
//

#ifndef GNU_COINCHANGE_H
#define GNU_COINCHANGE_H
using namespace std;

#include <iostream>
#include <vector>

class CoinChange {
public:
    int coinChangeHelper(const vector<int> &denominations, int total, int currentIdx) {

        if (total < 0) {
            return 0;
        }

        if (total == 0) {
            return 1;
        }

        if ((denominations.empty()) || (currentIdx >= denominations.size())) {
            return 0;
        }

        int denominationsInc, denominationExl;
        int newTotal = total - denominations[currentIdx];
        denominationsInc = coinChangeHelper(denominations, newTotal, currentIdx);
        denominationExl = coinChangeHelper(denominations, total, currentIdx + 1);
        return (denominationsInc + denominationExl);
    }

    int countChange(const vector<int> &denominations, int total) {
        if (total <= 0) {
            return 0;
        }

        if (denominations.size() == 0) {
            return 0;
        }

        int currentIdx = 0;
        int nWays = 0;
        nWays  = coinChangeHelper(denominations, total, currentIdx);
        return nWays;
    }
};

void
test_coinChange() {
    CoinChange *cc = new CoinChange();
    vector<int> denominations = {1, 2, 3};
    cout << cc->countChange(denominations, 5) << endl;

    delete cc;
}
#endif //GNU_COINCHANGE_H
