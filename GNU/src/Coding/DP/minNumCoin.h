//
// Created by kamr on 11/17/2021.
//

#ifndef GNU_MINNUMCOIN_H
#define GNU_MINNUMCOIN_H
#include <vector>
#include <climits>

using namespace std;

int minNumberOfCoinsForChangeInt(int target, vector<int> denoms, int currIdx, vector<int> &denCount) {
    if (target < 0) {
        return INT_MAX;
    }

    if (currIdx >= denoms.size()) {
        return INT_MAX;
    }

    if (target == 0) {
        return 0;
    }
    int include = INT_MAX;
    int exclude = INT_MAX;
    if (target-denoms[currIdx] >= 0){
        include = minNumberOfCoinsForChangeInt(target - denoms[currIdx], denoms, currIdx, denCount);
    }
    if (include != INT_MAX) {
        include = include + 1;
    }

    exclude = minNumberOfCoinsForChangeInt(target, denoms, currIdx + 1, denCount);
    int minCount = min(include, exclude);
    //denCount[target] = minCount;
    return minCount;
}

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
    if (n < 0) {
        return 0;
    }

    if (denoms.size() == 0) {
        return 0;
    }

    vector<int> denCount(n  + 1, 0);
    denCount[0] = 1;
    int currIdx = 0;
    int minCount = minNumberOfCoinsForChangeInt(n, denoms, currIdx, denCount);
    return minCount;
}

void
test_numberOfWaysOfCoinChange() {
    vector<int> denominations = {};
    int target = 0;
    int numberOfWays = 0;

    denominations = {1, 5, 10};
    target = 7;
    numberOfWays = minNumberOfCoinsForChange(target, denominations);
    cout << "Number of ways to make " << target << " usings  denominations { ";
    for (auto denomination:denominations) {
        cout << denomination << " ";
    }
    cout << " } is " << numberOfWays << endl;

}

#endif //GNU_MINNUMCOIN_H
