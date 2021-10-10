//
// Created by kamr on 9/3/2021.
//

#ifndef GNU_LQUEUE_H
#define GNU_LQUEUE_H

#include "Link.h"
#include "Queue.h"
#include <iostream>

template <typename E>
class LQueue : public Queue<E> {
private:
    Link<E> * front;
    Link<E> * rear;
    int size;

public:
    Lqueue(int sz = defaultSize) {
        front = rear = new Link<E> ();
        size = 0;
    }

    int length() {
        return size;
    }

    bool empty() {
        return (size == 0);
    }

    bool full() {
        return false;
    }

    const E & front() {
        if (empty()) {
            std::cout<< "Queue is empty" << std::endl;
            return nullptr;
        } else {
            return  front->next->data;
        }
    }

    const E & back() {
        if (full()) {
            std::cout << "Queue is full " << std::endl;
            return nullptr;
        } else {
            return rear->data;
        }
    }

    void enqueue(const E & data) {
        rear->next = new Link(data, nullptr);
        rear = rear->next;
        size++;
    }

    E dequeue() {
        if (empty()) {
            std::cout<<"Queue is Empty" << std::endl;
            return nullptr;
        }
        E it = front->next->data;
        Link *freeNode = front->next;
        front->next = front->next->next;
        if (rear == freeNode) {
            rear = front;
        }
        delete freeNode;
    }

    void clear() {
        Link *freeNode = nullptr;
        while(front->next != nullptr) {
            freeNode = front->next;
            front->next = freeNode->next;
            delete freeNode;
            size--;
        }
        rear = front;
        assert(size == 0);
    }

    ~LQueue() {
        clear();
        delete front;
    }
};


#endif //GNU_LQUEUE_H

