//
// Created by kamr on 11/17/2021.
//

#ifndef GNU_MINWAITINGTIME_H
#define GNU_MINWAITINGTIME_H

#include <vector>
#include <algorithm>
using namespace std;

int minimumWaitingTime(vector<int> queries) {
    if (queries.size() == 0) {
        return -1;
    }
    if (queries.size() == 1) {
        return 0;
    }
    sort(queries.begin(), queries.end());
    int waitingTime = 0;
    int currWaitingTime = 0;
    int total = 0;

    for (int i = 1; i < queries.size(); i++) {
        currWaitingTime = waitingTime + queries[i-1];
        waitingTime = currWaitingTime;
        total = total + waitingTime;
        cout << "Waiting: " << waitingTime <<  "  for data" << queries[i] << endl;
    }

    return total;
}
void test_minwaitingTime() {
    vector<int> q = {2, 1, 2, 3, 6};
    int waitingTime = minimumWaitingTime(q);
    cout << "WaitingTIme:" << waitingTime << endl;
}
#endif //GNU_MINWAITINGTIME_H
