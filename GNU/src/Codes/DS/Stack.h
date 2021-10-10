//
// Created by kamr on 9/3/2021.
//

#ifndef GNU_STACK_H
#define GNU_STACK_H

template <typename  E>
class Stack
{
private:
    /*
     * Stack (const Stack &) {}
     * Stack (Stack && ) {}
     * Stack & operator = (const Stack &) {}
     * Stack & operator = (Stack &&) {}
     */

public:
    /*
    Stack();
    virtual ~Stack() {}
    */
    virtual void clear() =0;
    virtual int size() const = 0;
    virtual const bool empty() const =0;
    virtual const bool full() const = 0;
    virtual E & top() const = 0;
    virtual void push(const E & item) = 0;
    virtual E  pop() = 0;
};
#endif //GNU_STACK_H
