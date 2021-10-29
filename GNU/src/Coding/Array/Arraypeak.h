//
// Created by kamr on 10/13/2021.
//

#ifndef GNU_ARRAYPEAK_H
#define GNU_ARRAYPEAK_H

#include<iostream>
#include<vector>
using namespace std;

void
PrintArray(vector<int> array) {
    cout << "{" ;
    for (auto &data:array) {
        cout<< data << " ";
    }
    cout << "}";
    cout << endl;
    cout << "size of array: " << array.size() << endl;
}

int
LongestPeak(vector<int> array) {
    int max = -1;
    int left, right;
    int count, curr, prev, idx, top;
    bool isPeak = false;
    vector<int> res, temp;

    cout << endl;
    PrintArray(array);
    if ((array.size() == 0) || (array.size() == 1) || (array.size() == 2)) {
        isPeak = false;
        return 0;
    }

    prev = 0;
    left = right = top = -1;

    for (idx = 1; idx < array.size(); idx++) {
        if (array[idx] > array[prev]) {
            if (left == -1) {
                left = prev;
                temp.push_back(array[prev]);
                temp.push_back(array[idx]);
                count = 2;
            } else {
                if (isPeak) {
                    if (max < count) {
                        max = count;
                        res.clear();
                        res = temp;
                    }
                    /*
                    cout << "Peak Over<dec>: " ;
                    cout << " Left:" << left << " --- " << array[left] ;
                    cout << " Top: " << top << " --- " << array[top];
                    cout << " Right: " << right <<" --- " << array[right] << endl;
                    PrintArray(temp);
                     */

                    left = prev;
                    right = top = -1;
                    isPeak = false;
                    temp.clear();
                    temp.push_back(array[prev]);
                    temp.push_back(array[idx]);
                    count = 2;
                } else {
                    temp.push_back(array[idx]);
                    count++;
                }
            }
        } else if (array[idx] < array[prev]) {
            if (left != -1) {
                if (top == -1) {
                    top = prev;
                    right = idx;
                    isPeak = true;
                    /*
                    cout << "Peak Found: " ;
                    cout << " Left: " << left << " --- " << array[left] << endl;
                    */

                } else {
                    right = idx;
                }
                temp.push_back(array[idx]);
                count++;
            }
        } else {
            if ((right != -1) && (top != -1) && (left != -1)) {
                /*
                cout << "Peak Over <same> :" ;
                cout << " Left: " << left <<" --- " << array[left] << ":" ;
                cout << " Top: " << top << " --- " << array[top] <<":" ;
                cout << " Right: " << right << " --- " << array[right]<< endl;
                PrintArray(temp);
                 */

                count = right - left + 1;
                if (max < count) {
                    max = count;
                    res.clear();
                    res = temp;
                    temp.clear();

                }
                isPeak  = false;
            }
            left = right = top = -1;
        }
        prev = idx;
    }

    if (isPeak) {
        /*
        cout << "Peak Over<end>:";
        cout << " Left: " << left <<" --- " << array[left] << ":" ;
        cout << " Top: " << top << " --- " << array[top] <<":" ;
        cout << " Right: " << right << " --- " << array[right]<< endl;
         */

        count = right - left + 1;
        if (max < count) {
            max = count;
            res.clear();
            res = temp;
            temp.clear();

        }
    }

    if (max != -1) {
        PrintArray(res);
        return max;
    } else {
        return 0;
    }
}



void test_LongestPeak()
{
    vector<int> array1{1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    vector<int> array2{1, 4, 10, 2};
    vector<int> array3{4, 0, 2};
    vector<int> array4{1, 2, 2, 0};
    vector<int> array5{1, 3, 2};
    vector<int> array6{1, 1, 1, 2, 3, 10, 12, -3, -3, 2, 3, 45, 800, 99, 98, 0, -1, -1, 2, 3, 4, 5, 0, -1, -1};
    int peakLength;


    cout << "Program to Test LongestPeak" << endl;

    peakLength = LongestPeak(array1);
    if (peakLength == -1) {
        cout << "No peak exist" << endl;
    } else {
        cout << "Length of longest Peak " << peakLength << endl;
    }

    peakLength = LongestPeak(array2);
    if (peakLength == -1) {
        cout << "No peak exist" << endl;
    } else {
        cout << "Length of longest Peak " << peakLength << endl;
    }

    peakLength = LongestPeak(array3);
    if (peakLength == -1) {
        cout << "No peak exist" << endl;
    } else {
        cout << "Length of longest Peak " << peakLength << endl;
    }

    peakLength = LongestPeak(array5);
    if (peakLength == -1) {
        cout << "No peak exist" << endl;
    } else {
        cout << "Length of longest Peak " << peakLength << endl;
    }

    peakLength = LongestPeak(array6);
    if (peakLength == -1) {
        cout << "No peak exist" << endl;
    } else {
        cout << "Length of longest Peak " << peakLength << endl;
    }

}
#endif //GNU_ARRAYPEAK_H
