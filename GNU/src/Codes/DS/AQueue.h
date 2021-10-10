//
// Created by kamr on 9/3/2021.
//


/*  To do
 * 1. add iterator class support
 * 2. use exceptions instead of log
 * 3. add a log file
 */
#ifndef GNU_AQUEUE_H
#define GNU_AQUEUE_H

#include "Queue.h"
#include <iostream>

template <typename  E>
class AQueue : public Queue<E>
{
private:
    int front;
    int rear;
    int maxSize;
    E *arr;

public:
    Aqueue(int sz = defaultSize) :maxSize(sz) {
        front = -1;
        rear = -1;
        arr = new E[maxSize];
    }

    void clear() {
        front = rear = -1;
    }

    void bool empty() {
        bool ret = false;
        if (front == -1)  {
            ret = true;
        }
        return ret;
    }

    void bool full() {
        bool ret = false;

        if  ((rear + 1) % maxSize) == front) {
            ret = true;
        }

        return ret;
    }


    int length() {
        if (rear > front) {
            return (rear - front + 1);
        } else {
            return (front - rear + maxSize - 1);
        }
    }

    void enqueue(const E & elm) {
        if (full()) {
            /* remove with exception */
            std::cout<< "Queue is full" << std::endl;
            return;
        }

        rear = (rear + 1) % maxSize;
        arr[rear] = elm;
        if (front == -1) {
            front = 0;
        }
    }

    E dequeu() {
        if (empty()) {
            std::cout<<"Queue is empty" << std::endl;
            return nullptr;
        }

        E elm = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }

        return elm;
    }

    ~AQueue() {
        delete[] arr;
        front = rear = -1;
        maxSize = 0;
    }
};

#endif //GNU_AQUEUE_H
