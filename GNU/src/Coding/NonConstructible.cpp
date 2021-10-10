//
// Created by kamr on 9/27/2021.
//

#include<vector>
#include <algorithm>

using namespace std;

int nonConstructibleChange(vector<int> coins) {
    int sum = 0;
    if (coins.empty()) {
        return 1;
    }
    sort(coins.begin(), coins.end());

    if (coins[0] > 1) {
        return 1;
    }

    sum = coins[0];
    for (int i = 1; i < coins.size(); i++) {
        if (sum + 1 < coins[i]) {
            return sum + 1;
        } else {
            sum = sum + coins[i];
        }
    }
    return sum + 1;
}