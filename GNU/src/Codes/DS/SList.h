//
// Created by kamr on 9/3/2021.
//

#ifndef GNU_SLIST_H
#define GNU_SLIST_H

#include "link.h"
#include "list.h"

template <typename E>
class SList:public List<E>
{
private:
    Link<E> *head;
    Link<E> *tail;
    Link<E> *curr;
    int count;

    void init() {
        curr = head = new Link<E>(nullptr);
        tail = new Link<E> (nullptr);
        head->next = tail;
        count = 0;
    }
public:
    SList() { init();}

    ~SList() { clear();}

    void clear() {
        while (head != nullptr) {
            curr = head;
            head = head->next;
            delete curr;
            count--;
        }
    }
    void reinit() { clear(); init(); }

    int length() const { return  count; }

    bool empty() const { return (count == 0); }

    void insert(const E &item) {
        curr->next = new Link<E>(item, curr->next);
        if (tail == curr) {
            tail = curr->next;
        }
        count++;
    }

    void append(const E & item) {
        Link<E> *temp = head;
        while(temp->next != tail) { temp = temp->next; }
        Link<E> *newNode =  new Link<E>(item, temp->next);
        temp->next = newNode;
        count++;
    }

    void push_front(const E& item) {
        Link<E> *newNode = new Link<E>(item, head->next);
        head->next = newNode;
        count++;
    }

    void push_back(const E& item) {
        append(item);
    }

    void pop_front() {
        Link<E> *freeNode = head->next;
        head = head->next;
        if (curr = freeNode) {
            curr = head->next;
        }
        count--;
        delete freeNode;
    }

    void pop_back() {
        Link<E> *freeNode, *temp, *prev;
        temp = head;
        while (temp->next != tail) {
            prev = temp;
            temp - temp->next;
        }

        freeNode = temp;
        if (freeNode == head)  {
            return;
        }

        prev->next = tail;
        delete freeNode;
        count--;
    }

    void remove() {
        if (curr->next == tail) { return;}
        Link<E> *freeNode = curr->next;
        curr->next = curr->next->next;
        count--;
        delete freeNode;
    }

    void moveToStart() { curr = head;}

    void moveToEnd() { curr = tail; }

    void moveToPos(const int &pos) {
        if (pos < 0 && pos >= count) {
            return;
        }
        curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }
    }

    void prev() {
        if (curr  == head) { return;}
        Link<E> *temp = head;
        while (temp->next != curr) {
            temp = temp->next;
        }
        curr = temp;
    }

    void next()  { curr = curr-> next; }

    int currPos() const {
        Link<E> *temp = head;
        int idx = 0;
        if (head == curr) {
            return 0;
        }
        while (temp != curr) {
            temp = temp->next;
            idx = idx + 1;
        }
        return  idx;
    }

    const E& getValue() const {
        assert(curr->next != tail);
        return curr->next->data;
    }

    const E & front() const {
        return head->next->data;
    }

    const E & back() const {
        assert(empty());
        Link<E> *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        return temp->data;
    }

    bool find(const E &data) const {
        if (empty()) return false;
        bool ret = false;
        Link<E> *temp = head->next;
        while(temp->next != tail) {
            if (temp->data == data) { ret = true; break;}
            temp = temp->next;
        }
        return ret;
    }
};

#endif //GNU_SLIST_H
