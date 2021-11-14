//
// Created by kamr on 11/14/2021.
//

#ifndef GNU_SEARCHFORRANGE_H
#define GNU_SEARCHFORRANGE_H

using namespace std;
vector<int> searchForRangeInt(vector<int> array, int start, int end, int target) {
    if (start <= end) {
        int mid = (start + end )/2;
        if (array[mid] > target) {
            return searchForRangeInt(array, start, mid - 1, target);
        } else if (array[mid] < target) {
            return searchForRangeInt(array, mid + 1, end, target);
        } else {
            int ltIdx = mid;
            int rtIdx = mid;
            while (array[ltIdx] == target) {
                ltIdx = ltIdx - 1;
            }
            ltIdx = ltIdx + 1;

            while (array[rtIdx] == target) {
                rtIdx = rtIdx + 1;
            }
            rtIdx = rtIdx - 1;
            return {ltIdx, rtIdx};
        }
    } else {
        return {-1, -1};
    }
}

vector<int> searchForRange(vector<int> array, int target) {
    vector<int> output = {-1, -1};

    if (array.size() == 0) {
        return output;
    }

    if (array.size() == 1) {
        if (array[0] == target) {
            output = {0, 0};
            return output;
        } else {
            output = {-1, -1};
            return output;
        }
    }
    int start = 0;
    int end = array.size() - 1;
    output = searchForRangeInt(array, start, end, target);
    return output;
}
#endif //GNU_SEARCHFORRANGE_H
