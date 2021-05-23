//
// Created by Raj Kamal on 02/04/21.
//

#include "qsort.h"
#include <vector>
#include <iostream>


void QSort :: Swap(std::vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int QSort :: Partition(std::vector<int> &arr, int start, int end)
{
    int pivot_data = arr[end];
    int j = start - 1;
    int i = start;

    while(i < end) {
        if (arr[i] < pivot_data) {
            j = j + 1;
            Swap(arr, i, j);
        }
        i  = i + 1;
    }
    j = j + 1;
    Swap(arr, j, end);
    return j;
}

void QSort ::QuickSort(std::vector<int> &arr, int start, int end)
{
    int pivot;
    if (start < end) {
        pivot = Partition(arr, start, end);
        QuickSort(arr, start, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

void QSort :: Sort(std::vector<int> &arr)
{
    if (arr.size() == 1) {
        return;
    }
    QuickSort(arr, 0, arr.size() - 1);
}