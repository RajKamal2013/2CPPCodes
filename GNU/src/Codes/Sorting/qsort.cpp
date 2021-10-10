//
// Created by Raj Kamal on 02/04/21.
//

#include "qsort.h"
#include <vector>
#include <iostream>

QSort :: QSort(std::vector<int> arr, int size)
{
    this->arr = arr;
    this->size = size;
}

void QSort :: swap(int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

int QSort :: partition(int start, int end)
{
    int pivot_data = arr[end];
    int j = start - 1;
    int i = start;

    while(i < end) {
        if (arr[i] < pivot_data) {
            j = j + 1;
            swap(i, j);
        }
        i  = i + 1;
    }
    j = j + 1;
    swap(j, end);
    return j;
}

void QSort ::quicksort(int start, int end)
{
    int pivot;
    if (start < end) {
        pivot = partition(start, end);
        quicksort(start, pivot - 1);
        quicksort(pivot + 1, end);
    }
}

std::vector<int> QSort :: run()
{
    int start = 0;
    int end = this->arr.size() - 1;
    quicksort(start, end);
    return std::move(arr);
}