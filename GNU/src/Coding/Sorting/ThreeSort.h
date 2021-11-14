//
// Created by kamr on 11/14/2021.
//

#ifndef GNU_THREESORT_H
#define GNU_THREESORT_H

/*
 *
 * First array consists of numbers from second array. Second array has pattern and first array has to be sorted
   according to the pattern

    first array {x, z, y, z, z, z, y, x ,  x  x}
    Second array -> {x, y, z}

    Output =>
    {x, x, x, x, y, y, z, z, z, z}
 */
vector<int> threeNumberSort(vector<int> array, vector<int> order) {
    if (array.size()== 0) {
        return {};
    }
    if (array.size() == 1) {
        return array;
    }
    int x, y, z;
    x = order[0];
    y = order[1];
    z = order[2];
    // count total occurance of x, y, z
    int xCount, yCount, zCount;
    xCount = yCount = zCount = 0;
    for (int idx = 0; idx < array.size(); idx++) {
        if (array[idx] == x) {
            xCount++;
        } else if (array[idx] == y) {
            yCount++;
        } else {
            zCount++;
        }
    }
    int xStart = 0 ;
    int xEnd = xStart  + xCount - 1;
    int yStart = xEnd + 1;
    int yEnd = yStart + yCount - 1;
    int zStart = yEnd + 1;
    int zEnd = zStart + zCount - 1;
    for (int idx = xStart; idx <= xEnd; idx++ ) {
        array[idx] = x;
    }
    for (int idx = yStart; idx <= yEnd; idx++) {
        array[idx] = y;
    }

    for (int idx = zStart; idx <= zEnd; idx++) {
        array[idx] = z;
    }
    return array;
}


vector<int> threeNumberSort2(vector<int> array, vector<int> order) {
    if (array.size()== 0) {
        return {};
    }
    if (array.size() == 1) {
        return array;
    }
    int x, y, z;
    x = order[0];
    y = order[1];
    z = order[2];
    // count total occurance of x, y, z
    int xCount, yCount, zCount;
    int xStart = 0;
    xCount = yCount = zCount = 0;
    for (int idx = 0; idx < array.size(); idx++) {
        if (array[idx] == x) {
            xCount++;
        } else if (array[idx] == y) {
            yCount++;
        } else {
            zCount++;
        }
    }
    int xIdx = 0 ;
    for (int idx = 0; idx < array.size(); idx++) {
        if (array[idx] == x) {
            swap(array[idx], array[xIdx]);
            xIdx++;
        }
    }
    int yIdx = xStart  + xCount;
    for (int idx = 0; idx < array.size(); idx++) {
        if (array[idx] == y) {
            swap(array[idx], array[yIdx]);
            yIdx++;
        }
    }

    return array;
}


#endif //GNU_THREESORT_H
