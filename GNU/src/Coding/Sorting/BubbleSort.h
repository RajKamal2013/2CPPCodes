//
// Created by kamr on 11/3/2021.
//

#ifndef GNU_BUBBLESORT_H
#define GNU_BUBBLESORT_H

vector<int> bubbleSort(vector<int> array) {
    int temp;
    if (array.size() == 0 || array.size() == 1) {
        return array;
    }
    for (int i = 0; i < array.size(); i++) {
        for (int j = i; j < array.size(); j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}

#endif //GNU_BUBBLESORT_H
