//
// Created by kamr on 9/2/2021.
//

#ifndef GNU_DLIST_H
#define GNU_DLIST_H


#include <iostream>
#include <algorithm>

template <typename Object>
class DList {
private:
    struct Node {
        Object data;
        Node *prev;
        Node *next;

        Node(const Object &d = Object {}, Node *p = nullptr, Node *n = nullptr) :
            data { d }, prev { p }, next { n } {}

        Node(const Object &&d, Node *p = nullptr, Node *n = nullptr) :
            data { std::move(d) }, prev{ p }, next{ n } {}
    };

private:
    int theSize;
    Node *head;
    Node *tail;

    void init() {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

public:
    class iterator {
    protected:
        Node *current;

        const Object &retrieve() const {
            return current->data;
        }

        iterator(Node *p) : current{p} {}

        friend class DList<Object>;
    public:
        iterator() : current{nullptr} {}

       const Object &operator*() const { return retrieve(); }

        iterator & operator--()   {
            current = current->prev;
            return *this;
        }

        iterator & operator++()  {
            current = current->next;
            return *this;
        }

        bool operator==(const iterator &rhs) const {
            return (current == rhs.current);
        }

        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }
    };

public:

    DList() { init(); }


    DList(DList &rhs) {
        init();
        for (auto &x:rhs) {
            push_back(x);
        }
    }

    DList &operator=(DList &rhs) {
        DList copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    DList(DList &&rhs): theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail} {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    DList &operator=(DList &&rhs) {
        std::swap(theSize, rhs.theSize);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return *this;
    }

    iterator begin() const  {
        return iterator(head->next);
    }

    iterator end()  const {
        return iterator(tail);
    }

    int size() { return theSize;}

    bool empty() { return (theSize == 0); }



    Object & front() const {
        return *begin();
    }

    Object & back() const  {
        return * --end();
    }

    void push_front(Object &x) {
        insert(begin(), x);
    }

    void push_back(Object &x) {
        insert(end(), x);
    }

    void pop_front() {
        erase(begin());
    }

    void pop_back() {
        erase(--end());
    }

    void append(Object &x) {
        push_back(x);
    }

    iterator insert(iterator itr, Object &x) {
        Node *p = itr.current;
        theSize++;
        Node *newNode = new Node{x, p->prev, p};
        p->prev = p->prev->next = newNode;
        return iterator(newNode);
    }

    iterator erase(iterator itr) {
        Node *p = itr.current;
        iterator curr(p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        return curr;
    }


    bool find(Object &x = Object { })  const {
        bool ret = false;
        for (auto &itr:*this) {
            if (itr == x) {
                ret = true;
                break;
            }
        }
        return ret;
    }

    void clear( )
    {
        while( !empty( ) )
            pop_front( );
    }

    ~DList() {
        clear();
        delete head;
        delete tail;
        theSize = 0;
    }
};

#endif //GNU_DLIST_H
