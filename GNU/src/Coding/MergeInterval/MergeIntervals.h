//
// Created by kamr on 11/10/2021.
//

#ifndef GNU_MERGEINTERVALS_H
#define GNU_MERGEINTERVALS_H


using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
public:
    int start = 0;
    int end = 0;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class MergeIntervals {
public:
    static vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(),
             [](const Interval &x, const Interval &y) {return x.start < y.start;});

        vector<Interval> mergedIntervals = {};
        Interval c(0, 0), b(0, 0);
        int idx;
        bool pushed;

        idx = 0;
        c.start = intervals[idx].start;
        c.end = intervals[idx].end;
        pushed = false;
        idx = 1;

        while (idx < intervals.size()) {
            b = intervals[idx];
            if (b.start <= c.end) { //overlapping
                c.end = max(c.end, b.end);
                idx = idx + 1;
            } else {
                mergedIntervals.push_back(c);
                pushed = true;
                c.start = intervals[idx].start;
                c.end = intervals[idx].end;
                pushed = false;
                idx = idx + 1;
            }
        }

        if (!pushed) {
            mergedIntervals.push_back(c);
        }

        return mergedIntervals;
    }
};

void
test_mergedIntervals() {
    vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
    cout << "Merged intervals: ";
    for (auto interval : input) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = {{6, 7}, {2, 4}, {5, 9}};
    for (auto interval : input) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = {{1, 4}, {2, 6}, {3, 5}};
    for (auto interval : input) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
}
#endif //GNU_MERGEINTERVALS_H
