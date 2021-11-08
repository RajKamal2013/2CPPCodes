//
// Created by kamr on 11/5/2021.
//

#ifndef GNU_LARGESTTHREENUMBER_H
#define GNU_LARGESTTHREENUMBER_H

/*
 * Find largest three number

Given an array of atleast 3 number, find the largest 3 number.

Input => {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7}
Output=> {18, 141, 541}

Input => {10, 5, 9, 10, 12}
Output => {10, 10, 12}

-> keep three numbers to track, max1, max2, max3 while iterating the array
 */

vector<int>
findThreeLargestNumbers(vector<int> array) {

    if (array.size() < 3) {
        return {};
    }

    int largest, secondLargest, thirdLargest;
    vector<int> output = {};

    if (array[0] >= array[1]) { // arr0 > arr1
        if (array[0] >= array[2]) {  // arr0 > arr2 and arr0 > arr1
            largest = array[0];
            if (array[2] >= array[1]) {  // arr2 and arr1 will fight.
                secondLargest = array[2];
                thirdLargest = array[1];
            } else {
                secondLargest  = array[1];
                thirdLargest = array[2];
            }
        } else {  //arr0 > arr1 and arr0 < arr2
            largest = array[2];
            secondLargest = array[0];
            thirdLargest = array[1];
        }
    } else { // arr1 > arr0
        if (array[1] >= array[2]) {  // arr1 > arr0 and arr1 > arr2 -> arr1 largest
            largest = array[1];
            if (array[2] >= array[0]) { // arr2 and arr0 will fight for next
                secondLargest = array[2];
                thirdLargest = array[0];
            } else {
                secondLargest = array[0];
                thirdLargest = array[2];
            }
        } else {  // arr0 > arr1 and arr0 <  arr2
            largest = array[2];
            secondLargest = array[0];
            thirdLargest = array[1];
        }
    }

    if (array.size() == 3) {
        output.push_back(thirdLargest);
        output.push_back(secondLargest);
        output.push_back(largest);
        return output;
    }

    for (int i = 3; i < array.size(); i++) {
        if (array[i] >= largest) {
            thirdLargest = secondLargest;
            secondLargest  = largest;
            largest = array[i];
        } else if ((array[i] < largest) && (array[i] >= secondLargest)) {
            thirdLargest = secondLargest;
            secondLargest = array[i];
        } else if ((array[i] < largest) && (array[i] < secondLargest) && (array[i] > thirdLargest)) {
            thirdLargest = array[i];
        } else {
            // do nothing;
        }
    }

    output.push_back(thirdLargest);
    output.push_back(secondLargest);
    output.push_back(largest);
    return output;
}

void
test_findThreeLargestNumbers() {
    vector<int> array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    vector<int> large = {};

    cout << "---------------------------------------" << endl;
    large = findThreeLargestNumbers(array);
    cout << "Input:" << endl;
    for (auto &data:array) {
        cout << data << " ";
    }
    cout << endl;

    cout << "Output :" << endl;
    for (auto &data:large) {
        cout << data << " ";
    }
    cout << endl;


    cout << "---------------------------------------" << endl;
    array = {10, 5, 9, 10, 12};
    large = findThreeLargestNumbers(array);
    cout << "Input:" << endl;
    for (auto &data:array) {
        cout << data << " ";
    }
    cout << endl;

    cout << "Output :" << endl;
    for (auto &data:large) {
        cout << data << " ";
    }
    cout << endl;


    cout << "---------------------------------------" << endl;
    array = {55, 43, 11, 3, -3, 10};
    large = findThreeLargestNumbers(array);
    cout << "Input:" << endl;
    for (auto &data:array) {
        cout << data << " ";
    }
    cout << endl;

    cout << "Output :" << endl;
    for (auto &data:large) {
        cout << data << " ";
    }
    cout << endl;
}


#endif //GNU_LARGESTTHREENUMBER_H



