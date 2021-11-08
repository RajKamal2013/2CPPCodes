//
// Created by kamr on 11/3/2021.
//

#ifndef GNU_INSERTIONSORT_H
#define GNU_INSERTIONSORT_H

vector<int>
insertionSort(vector<int> array) {
    if ((array.size() == 0) || (array.size() == 1)) {
        return array;
    }
    int i,j, temp;
    i = 1;
    j = 0;
    while (i < array.size()) {
        j = i - 1;
        int pivot = array[i];
        while ((j >= 0) && (array[j] > pivot)) {
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
            j--;
        }
        j++;
        if (array[j] > pivot) {
            temp = array[j];
            array[j] = pivot;
            array[i] = temp;
        }
        i++;
    }
    return array;
}
void
test_insertionSort() {
    vector<int> arr = {5, 7, 9, 0, 1, 4, 5};
    vector<int> sortedArr;
    cout << "Input " << endl;
    for (auto &data:arr) {
        cout << data << " ";
    }
    cout << endl;
    sortedArr = insertionSort(arr);
    cout << "Output" << endl;
    for (auto &data:sortedArr) {
        cout << data << " ";
    }
    cout << endl;
    return;
}


#endif //GNU_INSERTIONSORT_H
