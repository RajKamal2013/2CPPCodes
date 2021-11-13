//
// Created by kamr on 11/13/2021.
//

#ifndef GNU_RADIXSORT_H
#define GNU_RADIXSORT_H

using namespace  std;
#include <vector>
#include <valarray>


class RadixSort {
    int base;
    int R;
    bool dbgLog;
public:
    RadixSort(int base = 10) {
        this->base = 10;
        this-> R =  10;
        dbgLog = false;
    }
private:
    //base -> 10 for numbers
    int getDigit(int number, int pos, int maxD) {
        int divisor = (int) pow(base, pos);
        int digit = (number / divisor);
        if (digit > 0) {
            digit = digit % base;
            digit = digit + 1;
        } else {
            digit = 0;
        }
        /*
        if (dbgLog) {
            cout << "Digit<" << pos << ">" << " for number " << number << " is " << digit << endl;
        }
         */
        return digit;

    }

    // get maximum number of digits among all numbers in the array
    int maxNumberOfDigits(vector<int> array) {
        int maxDigit = 0;
        int d = 0;
        int number, divisor;
        for (auto data:array) {
            d = 0;
            number = data;
            while (number > 0) {
                divisor = (int)pow(base, d);

                divisor = (int)pow(base, d);
                number = data / divisor;
                d = d + 1;
            }
            if (maxDigit < d) {
                maxDigit = d;
            }

        }
        return maxDigit;
    }

    //counting sort at position d for numbers in array.
    void countingSort(vector<int> &array, int d, int maxD) {
        // copy of array
        vector<int> aux(array);
        // for rank computation
        vector<int> rank(R + 2, 0);

        int digitAtPos;

        // compute frequency
        for (int idx = 0; idx < array.size(); idx++) {
            digitAtPos = getDigit(array[idx], d, maxD);   // mapping each number to 0 to 9
            rank[digitAtPos] = rank[digitAtPos] + 1;
        }

        // compute ranks
        for (int idx = 1; idx <= R + 2; idx++) {
            rank[idx] = rank[idx] + rank[idx - 1];
        }

        // copy  back -> <in place u need to start from end >
        for (int idx = array.size() - 1; idx >= 0; idx--) {
            digitAtPos = getDigit(array[idx], d, maxD);
            aux[rank[digitAtPos] - 1] = array[idx];
            rank[digitAtPos] = rank[digitAtPos] - 1;
        }

        // copy back
        for (int idx = 0; idx < array.size(); idx++) {
            array[idx] = aux[idx];
        }
        if (dbgLog) {
            cout << "Sorted at D: " << d << endl;
            display(array);
            display(aux);
        }

    }

    void display(vector<int>arr) {
        if (dbgLog) {
            for (auto number:arr) {
                cout << number << " ";
            }
            cout << endl;
        }
    }

public:
    //call counting sort for each position d (0 to max d in all the numbers)
    void run(vector<int> &array, int R) {
        this->base = R;
        this->R = R;
        // calculate maximum digit among all numbers in array
        int maxD = maxNumberOfDigits(array);
        cout << "max digit :" << maxD << endl;

        for (int d = 0; d < maxD; d++) {
            countingSort(array, d, maxD);
        }
    }
};

vector<int> radixSort(vector<int> array) {
    if (array.size() == 0) {
        return {};
    }

    if (array.size() == 1) {
        return array;
    }

    int base = 10;
    RadixSort *sort = new RadixSort();
    sort->run(array, base);
    return array;
}


void test_radixSort() {
    vector<int> arr = {8762, 654, 3008, 345, 87, 65, 234, 12, 2};
    vector<int> sortedArr;


    arr = {8762, 654, 3008, 345, 87, 65, 234, 12, 2, 100000};
    cout << "Input " << endl;
    for (auto &data:arr) {
        cout << data << " ";
    }
    cout << endl;
    sortedArr = radixSort(arr);
    cout << "Output" << endl;
    for (auto &data:sortedArr) {
        cout << data << " ";
    }
    cout << endl;
    return;
}
#endif //GNU_RADIXSORT_H
