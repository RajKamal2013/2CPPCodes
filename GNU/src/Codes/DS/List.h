//
// Created by kamr on 9/3/2021.
//

//#ifndef GNU_LIST_H
//#define GNU_LIST_H

#include <algorithm>

template <typename E>
class List
{
    /*
private:
    List(const List &) { }
    List & operator = (const List &) { }
    List(List &&) { }
    List & operator = (List &&) { }
     */
public:
    /*
    List() { }
    ~List() { }
     */
    virtual int length() const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
    virtual void reinit() = 0;
    virtual void insert(const E & item) = 0;
    virtual void append(const E &item) = 0;
    virtual void push_front(const E &item)  = 0;
    virtual void push_back(const E &item) = 0;
    virtual void remove() = 0;
    virtual void pop_back() = 0;
    virtual void pop_front()  = 0;
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void moveToPos(const int &pos) = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual int currPos() const = 0 ;
    virtual const E& getValue() const = 0;
    virtual const E & front() const = 0;
    virtual const E & back() const = 0;
    //virtual const bool find(E & obj) const  = 0;

    /* Add iterator class */
};

//#endif //GNU_LIST_H
