//
// Created by kamr on 11/10/2021.
//

#ifndef GNU_CONTINUOUSMEDIAN_H
#define GNU_CONTINUOUSMEDIAN_H

using namespace std;
#include <queue>
#include <vector>

class ContinuousMedianHandler {
public:
    double median;
    priority_queue<int> maxHeap = {};
    priority_queue<int, vector<int>, greater<int>> minHeap = {};

    void insert(int number) {
        if ((minHeap.empty()) || (maxHeap.top() > number)) {
            maxHeap.push(number);
        } else {
            minHeap.push(number);
        }

        int countMin = minHeap.size();
        int countMax = maxHeap.size();

        if (countMax  > countMin + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (countMax < countMin) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else {

        }

        countMin = minHeap.size();
        countMax = maxHeap.size();

        if (countMin == countMax) {
            median = ((double)maxHeap.top()/2 + (double)minHeap.top()/2);
        } else {
            median = maxHeap.top();
        }
    }

    double getMedian() { return median; }
};

void
test_ConitnousMedian() {
    ContinuousMedianHandler *NumberStream = new ContinuousMedianHandler();
    vector<int> input = {5, 10};
    for (auto data: input) {
        NumberStream->insert(data);
    }

    cout << "Median:" << NumberStream->getMedian() << endl;
}
#endif //GNU_CONTINUOUSMEDIAN_H
