//
// Created by kamr on 11/9/2021.
//

#ifndef GNU_MERGEKSORTEDARRAY_H
#define GNU_MERGEKSORTEDARRAY_H


struct Item {
    int arrIdx;
    int elementIdx;
    int value;
};



class MinHeapMergeSort {
public:
    vector<Item> heapItems;
    MinHeapMergeSort(vector<Item>array = {}) { heapItems = array; buildHeap();}

    void buildHeap() {
        for (int i = heapItems.size()/2; i >= 0; i--) {
            siftDown(i, heapItems.size() - 1);
        }
    }

    void siftDown(int currentIdx,int endIdx) {
        int left, right, smaller;
        Item temp;

        for (auto data:heapItems) {
            cout << data.value <<  " " ;
        }
        cout << endl;

        while (currentIdx <= endIdx) {
            left = 2 * currentIdx + 1;
            right = 2 * currentIdx + 2;

            if ((left <= endIdx) && (heapItems[left].value < heapItems[currentIdx].value)) {
                smaller = left;
            } else {
                smaller = currentIdx;
            }

            if ((right <= endIdx) && (heapItems[right].value < heapItems[smaller].value)) {
                smaller = right;
            }

            if (currentIdx != smaller ) {
                swap(heapItems[currentIdx], heapItems[smaller]);
                currentIdx = smaller;
            } else {
                break;
            }
        }
        for (auto data:heapItems) {
            cout << data.value <<  " " ;
        }
        cout << endl;
    }

    void siftUp(int currentIdx) {
        int parent = (currentIdx  - 1)/2;
        Item temp;
        while (currentIdx > 0) {
            if (heapItems[parent].value > heapItems[currentIdx].value) {
                temp = heapItems[currentIdx];
                heapItems[currentIdx] = heapItems[parent];
                heapItems[parent] = temp;
                currentIdx = parent;
                parent = (currentIdx - 1)/2;
            } else {
                break;
            }
        }
    }

    void insert(Item &data) {
        heapItems.push_back(data);
        if (heapItems.size() == 1) {
            return;
        }

        siftUp(heapItems.size() - 1);
    }

    Item removeMin() {
        Item min = {INT_MAX, INT_MAX, INT_MAX};
        if (heapItems.size() == 0) {
            return min;
        }
        min = heapItems[0];
        if (heapItems.size() == 1) {
            heapItems.pop_back();
            return min;
        }
        heapItems[0] = heapItems[heapItems.size() - 1];
        heapItems.pop_back();
        siftDown(0, heapItems.size() - 1);
        return min;
        }

        void showValue() {
            for (auto data:heapItems) {
                cout << data.value << " ";
            }
            cout << endl;
        }
};


    vector<int>
    mergeSortedArrays(vector<vector<int>> arrays) {
        vector<int> sortedArray = {};
        vector<Item> arrayElmt = {};
        vector<int> arr = {};
        Item item;
        for (int idx = 0; idx < arrays.size(); idx++) {
            arr = arrays[idx];
            item = {idx, 0, arr[0]};
            cout << "Pushing:" << item.value << endl;
            arrayElmt.push_back(item);
        }

        MinHeapMergeSort *heap = new MinHeapMergeSort(arrayElmt);
        heap->showValue();
        bool SortComplete = false;
        int arrIdx, elmtIdx, value;
        while (!SortComplete) {
            item = heap->removeMin();
            if (item.value == INT_MAX) {
                SortComplete = true;
                break;
            }
            cout <<"Removed: " << item.value << endl;
            sortedArray.push_back(item.value);
            arrIdx = item.arrIdx;
            elmtIdx = item.elementIdx;
            arr = arrays[arrIdx];
            while (elmtIdx == arr.size() - 1) {
                item = heap->removeMin();
                cout <<"Removed: " << item.value << endl;
                if (item.value == INT_MAX) {
                    SortComplete = true;
                    break;
                }
                sortedArray.push_back(item.value);
                arrIdx = item.arrIdx;
                elmtIdx = item.elementIdx;
                arr = arrays[arrIdx];
            }
            if (SortComplete) {
                break;
            } else {
                item = {arrIdx, elmtIdx + 1, arr[elmtIdx + 1]};
                cout <<"Inserting: " << item.value << endl;
                heap->insert(item);
            }
        }
        return sortedArray;
    }


void
test_mergeSortedArray() {
    vector<vector<int>> arrays = {};
    vector<int> array = {};
    vector<int> sortedArray = {};

    array = {1, 5, 9, 21};
    arrays.push_back(array);

    array = { -1, 0};
    arrays.push_back(array);

    array = {-124, 81, 121};
    arrays.push_back(array);

    array = {3, 6, 12, 20, 150};
    arrays.push_back(array);

    cout << "--------------------------------------------------------" << endl;
    cout << "Input : <arrays> " << endl;
    for (auto &list:arrays) {
        cout << "{ ";
        for (auto &data: list) {
            cout << data << " ";
        }
        cout << "}" << endl;
    }

    cout << "Output <Sorted Array after merging sorted Array> " << endl;
    sortedArray = mergeSortedArrays(arrays);
    cout << "{ " ;
    for (auto &data:sortedArray) {
        cout << data << " ";
    }
    cout<< "}" << endl;
}
#endif //GNU_MERGEKSORTEDARRAY_H
