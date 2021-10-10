//
// Created by kamr on 9/3/2021.
//

#ifndef GNU_LSTACK_H
#define GNU_LSTACK_H

/* To do
 * 1. add iterator class
 * 2. add exception instead of logs
 * 3. add log file
 */
#include <algorithm>
#include "Stack.h"

template <typename E>
class LStack: public Stack<E>
{
private:
    Link<E> *arr;
    int sTop;
    int maxSize;

public:
    static const int defaultSize=100;

    LStack(int sz = defaultSize) : maxSize{ sz } {
        arr = nullptr;
        sTop = -1;
    }

    void clear() {
        while(arr != nullptr) {
            Link<E> *freeNode = arr;
            arr = arr->next;
            delete freeNode;
            sTop--;
        }
    }

    int size() const {
        return sTop;
    }

    const bool empty() const {
        if (arr == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    const bool full() const {
        return false;
    }

    E & top() const {
        return arr->data;
    }

    void push(const E& item) {
        Link<E> *newNode = new Link<E>(item, arr);
        arr = newNode;
        sTop++;
    }

    E  pop() {
        E item = arr->data;
        Link<E> *freeNode = arr;
        arr = arr->next;
        delete freeNode;
        return item;
    }

    ~LStack() {
        clear();
    }

};
#endif //GNU_LSTACK_H
