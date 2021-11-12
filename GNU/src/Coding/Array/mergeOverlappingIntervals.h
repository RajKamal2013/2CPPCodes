//
// Created by kamr on 11/12/2021.
//

#ifndef GNU_MERGEOVERLAPPINGINTERVALS_H
#define GNU_MERGEOVERLAPPINGINTERVALS_H

#include <vector>
#include <algorithm>
using namespace std;
/*
 * Merge OverLapping Intervals

 *   Intervals -> vector<vector<int>> intervals
 *   Input ->
 *       {{1, 2}, {3, 5}, {4, 7}, {6, 8}, {9, 10}}
 *   Output ->
 *       {{1, 2}, {3, 8}, {9, 10}}

 */

vector<vector<int>>
mergeOverlappingIntervals(vector<vector<int>> intervals) {
    bool dbgLog = false;
    if (intervals.size() == 0) {
        if (dbgLog) {
            cout << __LINE__ << " return" << endl;
        }
        return {};
    }

    if (intervals.size() == 1) {
        return intervals;
    }

    //output
    vector<vector<int>> sortedIntervals = intervals;
    vector<vector<int>> mergedIntervals = {};
    // track merged Interval entry
    vector<int> interval = {};
    bool pushed = false; //indicate interval is pushed to output or not.
    // idx to track the current position
    int currIdx = 0;
    vector<int> currInterval= {};
    int start = 0;
    int end = 1;

    // sort based on starting time.
    sort(sortedIntervals.begin(), sortedIntervals.end(), ([](const vector<int> &a, const vector<int> &b) {return (a[0] < b[0]);}));

    if (dbgLog) {
        cout << "Sorted Intervals " << endl;
        for (auto interval:sortedIntervals) {
            cout << "{ ";
            for (auto &data:interval) {
                cout << data << " ";
            }
            cout << "} ";
        }
        cout << endl;
    }

    currIdx = 0;
    currInterval = sortedIntervals[currIdx];
    interval = currInterval;
    pushed = false;


    currIdx = currIdx + 1;

    while(currIdx < sortedIntervals.size()) {
        currInterval = sortedIntervals[currIdx];
        // end is greater then current start -> overlapp

        if (interval[end] >= currInterval[start]) {
            interval[end] = max(interval[end], currInterval[end]);
            currIdx = currIdx + 1;

        } else { // no overlap , we place the interval formed in mergedIntervals
            mergedIntervals.push_back(interval);
            pushed = true;
            interval = currInterval;
            pushed = false;
            currIdx = currIdx + 1;
        }
    }

    if (!pushed) {
        mergedIntervals.push_back(interval);
    }

    if (dbgLog) {
        cout << __LINE__ << " return -> Size" << mergedIntervals.size() <<  endl;
    }

    return mergedIntervals;
}

void
test_mergeInterval() {
    vector<vector<int>> intervals = {};
    vector<vector<int>> mergedIntervals = {};
    vector<vector<int>> curr = {};

    intervals = {{1, 2}, {4, 7}, {3, 5}, {6, 8}, {9, 10}};
    curr = intervals;
    cout << "Input <Intervals> " << endl;
    for (auto interval:curr) {
        cout << "{ ";
        for (auto &data:interval) {
            cout << data << " ";
        }
        cout << "} ";
    }
    cout << endl;

    cout << "Output <merged Intervals > " << endl;
    mergedIntervals = mergeOverlappingIntervals(intervals);
    curr= mergedIntervals;
    for (auto interval:curr) {
        cout << "{ ";
        for (auto &data:interval) {
            cout << data << " ";
        }
        cout << "} ";
    }
    cout << endl;
}

#endif //GNU_MERGEOVERLAPPINGINTERVALS_H
