//
// Created by kamr on 8/31/2021.
//


// -----------------------work on exception ---------------
#ifndef GNU_ALIST_H
#define GNU_ALIST_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

template <typename Object>
class AList {
public:
    static const int MIN_CAPACITY = 2;

    AList( int initSize = 0) :
            theSize{0}, theNullObjs{0}, theCapacity{initSize + MIN_CAPACITY} {
            objects = new Object[theCapacity];
    }

    // Copy Constructor
    AList(const AList &rhs):
            theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, theNullObjs{rhs.theNullObjs}, objects {NULL} {
                objects = new Object[theCapacity];
                for (int k = 0; k < theNullObjs; k++) {
                    objects[k] = rhs.objects[k];
                }
    }

    // Copy Assignment
    AList & operator = (const AList &rhs) {
        AList copy = rhs;
        std::copy(*this, copy);
        return *this;
    }

    //Move Constructor
    AList(AList &&rhs) :
            theSize{rhs.theSize}, theNullObjs{rhs.theNullObjs}, theCapacity{rhs.theCapacity}, objects{rhs.objects} {
        rhs.objects = NULL;
        rhs.theSize = 0;
        rhs.theNullObjs = 0;
        rhs.theCapacity = 0;
    }

    //Move Assignment
    AList & operator = (AList &&rhs) {
        std::swap(theSize, rhs.theSize);
        std::swap(theCapacity, rhs.theCapacity);
        std::swap(theNullObjs, rhs.theNullObjs);
        std::swap(objects, rhs.objects);
        return *this;
    }

    //Destructor
    ~AList() {
        delete[] objects;
    }

    bool empty() {
        return (theSize == 0);
    }

    int size() const {
        return theSize;
    }
    int capacity() const {
        return theCapacity;
    }

    Object & operator[](int index) {
        if (index < 0 || index > size()) {
            assert("Index not good");
        }
        // throw exceptions
        return objects[index];
    }

    bool find(Object data) {
        bool ret = false;
        for (int k = 0; k < theSize; k++) {
            if (objects[k] == data) {
                ret = true;
                break;
            }
        }
        return ret;
    }

    int idx(Object data) {
        int index = -1;
        for (int k = 0; k < theSize; k++) {
            if (objects[k] == data) {
                index = k;
                break;
            }
        }
        return index;
    }

    void resize(int newCapacity) {
        Object *newArray = new Object[newCapacity];
        for (int k = 0; k < theSize; k++) {
            newArray[k] = std::move(objects[k]);
        }
        theCapacity = newCapacity;
        std::swap(objects, newArray);
        delete[] newArray;
    }

    void shrink() {
        int newCapacity = theCapacity/2;
        if (newCapacity == 0) {
            newCapacity = MIN_CAPACITY;
        }
        Object *newArray = new Object[newCapacity];
        int idx = 0;
        for (int k = 0; k < theSize; k++) {
            /* need to fix this */
            if (objects[k] == INT32_MAX) {
                continue;
            }
            newArray[idx] = objects[k];
            idx = idx + 1;
        }
        theSize = idx;
        theNullObjs = 0;
        theCapacity = newCapacity;
        std::swap(objects, newArray);
        delete[] newArray;
    }

    void append(Object data) {
        if( theSize == theCapacity )
            resize( 2 * theCapacity + 1 );
        objects[ theSize ] = data;
        theSize = theSize + 1;
    }

    void insert(Object data, int index) {
        if (theSize == theCapacity) {
            resize(2 * theCapacity + 1);
        }
        objects[index] = data;
    }

    void remove(Object data) {
        int index = -1;
        for (int k = 0; k < theSize; k++) {
            if (objects[k] == data) {
                index = k;
                break;
            }
        }

        if (index != -1) {
            objects[index] = INT32_MAX;
            theNullObjs = theNullObjs + 1;
        }

        int currSize = theSize - theNullObjs;
        if (currSize == theCapacity/4) {
            shrink();
        }
    }

    Object front() {
        if (empty()) {
            assert(0);
            return NULL;
        }
        return objects[0];
    }

    Object back() {
        return objects[theSize - 1];
    }

    typedef Object* iterator;
    iterator begin() {
        return &objects[ 0 ];
    }

    iterator end() {
        return &objects[ size( ) ];
    }

private:
    int theSize;
    int theCapacity;
    int theNullObjs;
    Object *objects;

};

#endif //GNU_ALIST_H


