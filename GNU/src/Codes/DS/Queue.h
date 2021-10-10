//
// Created by kamr on 9/3/2021.
//

#ifndef GNU_QUEUE_H
#define GNU_QUEUE_H

template<typename E>
class Queue
{
private:
    /*
    Queue(const Queue &) {}
    Queue(const Queue &&) {}
    Queue &operator = (const Queue &);
    Queue &operator = (Queue &&) {}
    */
public:
    Queue()  {}
    ~Queue() {}
    virtual void clear() = 0;
    virtual bool empty() = 0;
    virtual bool full() = 0;
    virtual int length() = 0;

    virtual void enqueue(const E &) = 0;
    virtual E dequeue() = 0;

    virtual const E& front() const = 0;

};

#endif //GNU_QUEUE_H
