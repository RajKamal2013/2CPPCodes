//
// Created by kamr on 11/7/2021.
//

#ifndef GNU_MINHEAP_H
#define GNU_MINHEAP_H

/*
 * Min heap Construction

    Implement a min Heap that supports
        1. Building a MinHeap from input array of integers
        2. Inserting integers in the heap
        3. Removing heap minimum / root value
        4. Peeking at heap's minimum/root value
        5. Shifting integers up and down the heap to maintain insertion and deletion

    Example of APIs
        array => 48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41
        MinHeap(array)
        buildHeap(array)  -> {-5, 2, 6, 7, 8, 8, 24, 391, 24, 56, 12, 24, 48, 41}
        insert(76)  ->  {-5, 2, 6, 7, 8, 8, 24, 391, 24, 56, 12, 24, 48, 41, 76}
        peek() -> -5
        remove() -> [2, 7, 6, 24, 8, 8, 24, 391, 76, 56, 12, 24, 48, 41]
        peek() -> 2
        remove() -> 2 [ 6, 7, 8, 24, 8, 24, , 24, 391, 76, 56, 12, 41, 48]
        peek() -> 6
        insert(87) -> [6, 7, 8, 24, 8, 24, , 24, 391, 76, 56, 12, 41, 48, 87]
*/

class MinHeap {
private:
    bool debugLog;
public:
    // keep the heap in vectors
    vector<int> heap;

    bool dbgLog;


    MinHeap(vector<int> vector) {
        this->heap = buildHeap(vector);
        this->dbgLog = true;
        this->debugLog = true;
    }

    // build heap from heap vector
    vector<int>
    buildHeap(vector<int> &heap) {
        if (heap.size() == 0) {
            return {};
        }
        int idx;
        // sift from nodes above leaves
        for (idx = 0; idx < heap.size(); idx++) {
            insert(heap[idx]);
        }
        return this->heap;
    }

    // go down to maintain heap property. -> removal or maintaining heap
    void
    siftDown(int currentIdx, int endIdx, vector<int> &heap) {
        if ((heap.size() == 0) || (heap.size() == 1)) {
            return;
        }

        int left, right, smaller, temp;

        while (currentIdx < endIdx) {
            left = 2 * currentIdx + 1;
            right = 2 * currentIdx + 2;

            if ((left < endIdx) && (heap[left] < heap[currentIdx])) {
                smaller = left;
            } else {
                smaller = currentIdx;
            }

            if ((right < endIdx) && (heap[right] < heap[smaller])) {
                smaller = right;
            }

            // swap
            if (smaller != currentIdx) {
                temp = heap[currentIdx];
                heap[currentIdx] = heap[smaller];
                heap[smaller] = temp;
                currentIdx = smaller;
            } else {
                break;
            }
        }
    }


// go up to maintain heap property, -> insertion in the heap
    void
    siftUp(int currentIdx, vector<int> &heap) {
        if ((heap.size() == 0) || (heap.size() == 1)) {
            return;
        }
        int parent, temp;

        parent = (currentIdx - 1)/2;
        while ((currentIdx > 0) && (heap[currentIdx] <= heap[parent])) {
            temp = heap[parent];
            heap[parent] = heap[currentIdx];
            heap[currentIdx] = temp;
            currentIdx  = parent;
            parent = (currentIdx - 1)/2;
        }
    }

    // min value ->
    int
    peek() {
        if (this->heap.size() == 0) {
            return -1;
        } else {
            return this->heap[0];
        }
    }

    int
    remove() {
        if (this->heap.size() == 0) {
            return -1;
        }
        int minValue, temp, len;
        minValue = this->heap[0];

        if (this->heap.size() == 1) {
            this->heap.pop_back();
            return minValue;
        }

        if (this->heap.size() == 2) {
           this->heap[0] = this->heap[1];
           this->heap.pop_back();
           return minValue;
        }

        this->heap[0] = this->heap[heap.size() - 1];
        this->heap.pop_back();
        //heap property
        siftDown(0, this->heap.size(), this->heap);
        return minValue;
    }

    void
    insert(int value) {

        int idx = this->heap.size();

        // heap is empty and we are inserting
        if (idx == 0) {
            this->heap.push_back(value);
            return;
        }

        this->heap.push_back(value);
        // place appropriately
        siftUp(idx, this->heap);
    }

    vector<int>&
    getData() {
        return this->heap;
    }

    void
    debugLogHeap() {
        cout << "Logging start : " << this->heap.size() << endl;
        for (int i = 0; i < this->heap.size(); i++) {
            cout << this->heap[i] << " ";
        }
        cout << endl;
    }
};


void
test_MinHeap() {
    MinHeap *heap;
    MinHeap *curr = nullptr;
    vector<int> input;
    vector<int> output;
    vector<int> heapElmt;
    int minValue, val;


    cout << "-------------------------------------------------" << endl;
    input = {48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41};

    cout << "Input <array>" << endl;
    for (auto &data:input) {
        cout << data << " ";
    }
    cout << endl;
    heap  = new MinHeap(input);
    curr = heap;
    cout << "Output:" << endl;
    output = curr->getData();
    for (auto &data:output) {
        cout << data << " ";
    }
    cout << endl;
    val = 76;
    cout << "Inserting " << val << endl;
    curr->insert(76);
    output = curr->getData();
    for (auto &data:output) {
        cout << data << " ";
    }
    cout << endl;

    cout << "peek :" << curr->peek() << endl;
    cout << "Removed :" << curr->remove() << endl;
    output = curr->getData();
    for (auto &data:output) {
        cout << data << " ";
    }
    cout << "peek :" << curr->peek() << endl;
    cout << "Removed :" << curr->remove() << endl;
    output = curr->getData();
    for (auto &data:output) {
        cout << data << " ";
    }
    cout << "peek :" << curr->peek() << endl;
    cout << "Removed :" << curr->remove() << endl;
    output = curr->getData();
    for (auto &data:output) {
        cout << data << " ";
    }
    cout << endl;
    val = 87;
    cout <<"Insert :" << val << endl;
    curr->insert(val);output = curr->getData();
    for (auto &data:output) {
        cout << data << " ";
    }





}
#endif //GNU_MINHEAP_H
