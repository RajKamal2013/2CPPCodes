//
// Created by kamr on 11/14/2021.
//

#ifndef GNU_FIRSTDUPLICATEVALUE_H
#define GNU_FIRSTDUPLICATEVALUE_H


#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array) {
    if ((array.size() == 0) || (array.size() == 1)) {
        return -1;
    }

    unordered_map<int, int> visited = {};
    int repeated = -1;
    for(auto data:array) {
        if (visited.find(data) == visited.end()) {
            visited[data] = 1;
        } else {
            repeated = data;
            break;
        }
    }

    return repeated;
}

#endif //GNU_FIRSTDUPLICATEVALUE_H
