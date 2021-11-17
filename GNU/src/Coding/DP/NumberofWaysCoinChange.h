//
// Created by kamr on 11/17/2021.
//

#ifndef GNU_NUMBEROFWAYSCOINCHANGE_H
#define GNU_NUMBEROFWAYSCOINCHANGE_H

#include <vector>
#include <iostream>
using namespace std;


int numberOfWaysToMakeChangeInt(int target, vector<int> denominations, int currIdx, vector<int> &denCount) {
    if (target < 0) {
        return 0;
    }

    if (target == 0) {
        return 1;
    }

    cout << endl;

    if (currIdx >= denominations.size()) {
        return 0;
    }

    /*
    if (denCount[target] > 0 ) {
        return denCount[target];
    }
     */


    int include  = numberOfWaysToMakeChangeInt(target - denominations[currIdx], denominations,  currIdx, denCount);
    int exclude =  numberOfWaysToMakeChangeInt(target, denominations, currIdx + 1, denCount);

    denCount[target] = include + exclude;

    return (include + exclude);
}

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    if (n <0) {
        return 0;
    }

    vector<int> denCount(n + 1, 0);
    denCount[0] = 1;
    int currIdx = 0;
    int count = numberOfWaysToMakeChangeInt(n, denoms, currIdx, denCount);

    int coin  = 0;
    /*
    for (auto data: denCount) {
        cout << "Number of Coins needed for " << coin << " " << data << endl;
        coin = coin + 1;
    }
    */
    return denCount[n];

}

void
test_numberOfWaysOfCoinChange() {
    vector<int> denominations = {};
    int target = 0;
    int numberOfWays = 0;

    denominations = {1, 5};
    target = 6;
    numberOfWays = numberOfWaysToMakeChange(target, denominations);
    cout << "Number of ways to make " << target << " using  denominations { " ;
    for (auto denomination:denominations) {
        cout << denomination << " ";
    }
    cout << "} is " << numberOfWays << endl;

}

#endif //GNU_NUMBEROFWAYSCOINCHANGE_H
