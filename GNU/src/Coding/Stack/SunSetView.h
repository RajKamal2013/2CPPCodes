//
// Created by kamr on 11/5/2021.
//

#ifndef GNU_SUNSETVIEW_H
#define GNU_SUNSETVIEW_H

/*
 * A building can be seen in sunset if  its strictly taller than all the buildings after it in the direction of sunset.
    Given height Array and direction of sunset , output the indices of building that can see the sunset.

    building = [3, 5, 4, 4, 3, 1, 3, 2 ]
    Direction = "EAST"
    Answer [1, 3, 6, 7]

    building = [3, 5, 4, 4, 3, 1, 3, 2 ]
    Direction = "WEST"
    -> 3, 5
    Answer [0, 1]

    WEST  -> RightWard (right)
    EAST  -> leftward  (left)

    -> First building facing the suset will be able to see.
    -> as I go (left/right), if the previous building (maxTillNow) is smaller then it will be seen ow not
    Keep MaxTillNow
 */

vector<int>
sunsetViews(vector<int> buildings, string direction) {
    vector<int> output = {};
    int maxTillNow;

    if (buildings.size() == 0 ) {
        return output;
    }

    if (buildings.size() == 1) {
        output.push_back(0);
        return output;
    }


    if (direction == "WEST") {
        maxTillNow = buildings[0];
        output.push_back(0);

        for (int idx = 1; idx < buildings.size(); idx++) {
            if (buildings[idx] > maxTillNow) {
                output.push_back(idx);
                maxTillNow = buildings[idx];
            }
        }
    } else if (direction == "EAST") {
        output.push_back(buildings.size() -1);
        maxTillNow = buildings[buildings.size() - 1];
        for (int idx = buildings.size() - 2; idx >= 0; idx--) {
            if (buildings[idx] > maxTillNow) {
                maxTillNow = buildings[idx];
                output.push_back(idx);
            }
        }
        reverse(output.begin(), output.end());
    } else {
        // do nothing
    }

    return output;
}


void
test_SunSetView() {
    vector<int> buildings = {3, 5, 4, 4, 3, 1, 3, 2};
    string direction = "EAST";
    vector <int> sunsetView = {};

    cout << "-------------------------------------------" << endl;
    sunsetView = sunsetViews(buildings, direction);
    cout<< "Input <Buildings>" << endl;
    for (auto &data:buildings) {
        cout << data << " ";
    }
    cout << endl;
    cout << "Direction:" << direction << endl;

    cout<< "Output <SunsetViews>" << endl ;
    for (auto &data:sunsetView) {
        cout << data << " ";
    }
    cout << endl;

    buildings = {3, 5, 4, 4, 3, 1, 3, 2};
    direction = "WEST";
    cout << "-------------------------------------------" << endl;
    sunsetView = sunsetViews(buildings, direction);
    cout<< "Input <Buildings>" << endl;
    for (auto &data:buildings) {
        cout << data << " ";
    }
    cout << endl;
    cout << "Direction:" << direction << endl;
    cout<< "Output <SunsetViews>" << endl;
    for (auto &data:sunsetView) {
        cout << data << " ";
    }
    cout << endl;



}
#endif //GNU_SUNSETVIEW_H
