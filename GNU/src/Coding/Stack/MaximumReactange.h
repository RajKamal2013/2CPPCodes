//
// Created by kamr on 11/4/2021.
//

#ifndef GNU_MAXIMUMREACTANGE_H
#define GNU_MAXIMUMREACTANGE_H


/*
 * Write a function that takes an array of positive integer representing height of adjacent building and
 * returns area of largest rectangle that can be created by adjacent buildings, including just
 * one building. All the buildings have same width (w = 1)

    Input -> buildings [1, 3, 3, 2, 4, 1, 5, 3, 2]
    answer -> 9
 * Psuedo code
    Insert heights in array.
    global_area

   After Every insertion at top
        height of top of element -> H
        curr area = H * 1;
        W = 1

       while (array is not empty -> i = 0 to array.size) {
            a = min(height, minimum(0, i)) * (w + i) ;
            curr_area = max(a, curr_area);
            global_area =  max (curr_area, global_area)
        }

    return global_area.
 *
 */


int findMin(vector<int> arr, int idx) {
    int min = INT_MAX;
    for (int i = (arr.size() - 1); i >= idx; i--) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int largestRectangleUnderSkyline(vector<int> buildings) {
    bool dbgLog = false;
    int global_area, curr_area, maxAreaTillNow;
    vector<int> Heights;
    int minHeightTillNow;
    int Width;

    if (buildings.size() == 0) {
        return 0;
    }

    if (buildings.size() == 1) {
        return buildings[0];
    }

    if (buildings.size() == 2) {
        int htMin = min(buildings[0], buildings[1]);
        int htMax = max(buildings[0], buildings[1]);
        int area = max(htMax, htMin * 2);
        return area;
    }

    Heights.push_back(buildings[0]);
    global_area  = buildings[0];

    for (int i = 1; i < buildings.size(); i++) {
        curr_area = buildings[i];
        if (dbgLog) {
            cout << "------------------------------------" << endl;
        }
        Width = 0;
        for (int idx = Heights.size() - 1; idx >= 0; idx-- ) {
            Width = Width + 1;
            minHeightTillNow = findMin(Heights, idx);
            maxAreaTillNow = minHeightTillNow * Width;
            if (dbgLog) {
                cout << setw(4) << "Area :" << curr_area;
                cout << " Data: " << buildings[i];
                cout << " MinHeight: " << minHeightTillNow;
            }

            maxAreaTillNow = max(curr_area, maxAreaTillNow);
            if (global_area < maxAreaTillNow) {
                global_area = maxAreaTillNow;
            }
            if (dbgLog) {
                cout << " MaxTillNow:" << maxAreaTillNow;
                cout << " Max:" << global_area << endl;
            }
        }
        Heights.push_back(buildings[i]);
    }
    curr_area = buildings[buildings.size()-1];

    if (dbgLog) {
        cout << "------------------------------------" << endl;
    }

    Width = 0;
    for (int idx = Heights.size() - 1; idx >= 0; idx-- ) {
        Width = Width + 1;
        minHeightTillNow = findMin(Heights, idx);
        maxAreaTillNow = minHeightTillNow * Width;
        if (dbgLog) {
            cout << setw(4) << "Area :" << curr_area;
            cout << " Data: " << buildings[buildings.size() - 1];
            cout << " MinHeight: " << minHeightTillNow;
        }

        maxAreaTillNow = max(curr_area, maxAreaTillNow);
        if (global_area < maxAreaTillNow) {
            global_area = maxAreaTillNow;
        }
        if (dbgLog) {
            cout << " MaxTillNow:" << maxAreaTillNow;
            cout << " Max:" << global_area << endl;
        }
    }
    return global_area;
}

void
test_maximumReatangle() {
    vector<int> heights = {1, 3, 3, 2, 4, 1, 5, 3, 2};
    int maxArea;

    cout << "------------------------------------" << endl;
    cout << "Inputs" << endl;
    for (auto &data: heights) {
        cout << data << " ";
    }
    cout << endl;
    maxArea = largestRectangleUnderSkyline(heights);
    cout << "Output" << endl;
    cout << "Maximum Area :" << maxArea;
    cout << endl;

    cout << "------------------------------------" << endl;
    heights = {4, 4, 4, 2, 2, 1};
    cout << "Inputs" << endl;
    for (auto &data: heights) {
        cout << data << " ";
    }
    cout << endl;
    maxArea = largestRectangleUnderSkyline(heights);
    cout << "Output" << endl;
    cout << "Maximum Area :" << maxArea;
    cout << endl;

    cout << "------------------------------------" << endl;
    heights = {1, 3, 3, 2, 4, 1, 5, 3};
    cout << "Inputs" << endl;
    for (auto &data: heights) {
        cout << data << " ";
    }
    cout << endl;
    maxArea = largestRectangleUnderSkyline(heights);
    cout << "Output" << endl;
    cout << "Maximum Area :" << maxArea;
    cout << endl;

    cout << "------------------------------------" << endl;
    heights = {25, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Inputs" << endl;
    for (auto &data: heights) {
        cout << data << " ";
    }
    cout << endl;
    maxArea = largestRectangleUnderSkyline(heights);
    cout << "Output" << endl;
    cout << "Maximum Area :" << maxArea;
    cout << endl;

}

#endif //GNU_MAXIMUMREACTANGE_H
