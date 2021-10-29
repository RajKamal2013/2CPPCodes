//
// Created by kamr on 10/28/2021.
//

#ifndef GNU_HEAP_H
#define GNU_HEAP_H


template<typename Comparable>
class BinaryMaxHeap {
private:
    Comparable *heap;
    int maxSize;
    int heapSize;
    bool test;

    bool isLeaf(int pos) {
        return ((pos > heapSize/2) && (pos < heapSize));
    }

    void maxHeapify(int pos) {
        int lt, rt, larger, temp;
        while (!isLeaf(pos)) {
            lt = 2 * pos + 1;
            rt = 2 * pos + 2;


            if ((lt < heapSize) && (heap[lt] > heap[pos]))
            {
                larger = lt;
            } else {
                larger = pos;
            }
            if ((rt < heapSize) && (heap[rt] > heap[larger]))
            {
                larger = rt;
            }
            if (larger != pos) {
                temp = heap[pos];
                heap[pos] = heap[larger];
                heap[larger] = pos;
            }
            pos = larger;
        }
    }

    void buildMaxHeap() {
        for (int i = heapSize / 2; i >= 0; i--) {
            maxHeapify(i);
        }
    }

    int parent(int pos) {
        return (pos - 1)/2;
    }
public:
    BinaryMaxHeap(int capacity = 100) {
        heapSize = 0;
        maxSize = capacity;
        test = true;
        heap = new Comparable[capacity];
    }

    BinaryMaxHeap(vector<Comparable> &item) {
        heap(item.size() + 100);
        heapSize = item.size();

        for (int i = 0;i < item.size(); item++) {
            heap[i] = item[i];
        }
        buildMaxHeap();
    }

    bool Empty() {
        return (heapSize == 0);
    }

    Comparable & findMax() {
        if (Empty()) {
            return {};
        } else {
            return heap[0];
        }
    }

    void insert(Comparable &x) {
       // assert(heapSize < maxSize);
       if (heapSize == 0) {
           heap[0] = x;
       }  else {
           int curr = heapSize;
           int temp, par;
           heap[curr] = x;
           par = parent(curr);
           if (test) {
               cout << "Start Insertion :" << x << endl;
           }
           while ((curr != 0) && (heap[curr] > heap[par])) {
               temp = heap[par];
               heap[par] = heap[curr];
               heap[curr] = temp;
               curr = par;
           }
       }
        if (test) {
            cout << "Done Insertion :" << x << endl;
        }
        heapSize++;
    }

    Comparable remove() {
        int temp;
        temp = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        if (heapSize != 0) {
            maxHeapify(0);
        }
        return temp;
    }

    Comparable top() {
        return heap[0];
    }
};

void test_maxheap()
{
    BinaryMaxHeap<int> heap;
    int data;
    data = 10;
    heap.insert(data);
    cout <<"Top heap:" << heap.top() << endl;
    data = 20;
    heap.insert(data);
    cout <<"Top heap:" << heap.top() << endl;
    data = -1;
    heap.insert(data);
    data = 15;
    heap.insert(data);
    cout <<"Top heap:" << heap.top() << endl;


    cout <<"Removing heap:" << heap.remove() << endl;
}

#endif //GNU_HEAP_H
