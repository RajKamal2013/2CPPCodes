//
// Created by kamr on 9/3/2021.
//

#ifndef GNU_ASTACK_H
#define GNU_ASTACK_H

#include "Stack.h"

/* To do
 * 1. add iterator class
 * 2. add exception instead of logs
 * 3. add log file
 */

template <typename E>
class AStack : public Stack<E>
{

private:
    int maxSize;
    int sTop;
    E *arr;

public:
    static const int defaultSize = 10;
    AStack(int size = defaultSize) : maxSize{ size }, sTop { -1 } {
        arr = new E[size];
    }

    ~AStack() {
        delete[] arr;
        sTop = -1;
        maxSize = 0;
    }

    void clear() {
        sTop = -1;
    }

    int size() const {
        return sTop + 1;
    }

    const bool empty() const {
        return (sTop == -1);
    }

    const bool full() const {
        if (sTop == maxSize - 1 ) {
            return true;
        } else {
            return false;
        }
    }

    E & top() const {
        assert(empty());
        return arr[sTop];
    }

    void push (const E& item) {
        assert(sTop != maxSize - 1);
        sTop++;
        arr[sTop] = item;
    }

    E  pop() {
        assert(sTop != -1);
        E &item = arr[sTop];
        sTop--;
        return item;
    }
};
#endif //GNU_ASTACK_H
