//
// Created by Raj Kamal on 27/08/22.
//

#ifndef GNU_DLL_H
#define GNU_DLL_H

#include<iostream>
#include<cstdio>
using namespace std;

const int BOGUS_DATA = INT32_MAX;

struct DLLNode {
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode() {
        
    }
};

class DLL {
    DLLNode *tail;
    int len;
    bool debug, warn;
    DLLNode *head;

public:
    DLL(){
        this->head = this->tail = nullptr;
        this->len = 0;
        this->debug = this->warn = true;
    }

    int length() {
        return this->len;
    }
    // Insert at the head of list
    /*
     * if head == nullptr -> initialize the node and make it head
     * else create new node and it's next point to head and head's
     * previous point to new node. Assign new node has new head.
     */
    void insert(int data) {
        assert(data != BOGUS_DATA);
        DLLNode *newNode = new DLLNode();
        newNode->data = data;
        newNode->next = newNode->prev = nullptr;
        this->len = this->len + 1;

        if (head == nullptr) {
            this->head = this->tail = newNode;
            return;
        }

        DLLNode *temp = this->head;
        newNode->next = temp;
        temp->prev = newNode;
        this->head  = newNode;
        return;
    }

    // append at the tail of the list
    void append(int data) {
        assert(data != BOGUS_DATA);
        DLLNode *newNode = new DLLNode();
        newNode->data = data;
        newNode->next = newNode->prev = nullptr;
        this->len = this->len + 1;

        if (tail == nullptr) {
            this->head = this->tail = newNode;
            return;
        }

        DLLNode *temp = this->tail;
        newNode->prev = temp;
        temp->next = newNode;
        this->tail = newNode;
        return;
    }

    // remove from the head of the node
    void pop() {
        //empty list
        if (this->head == nullptr) {
            assert(this->len == 0);
            if (this->warn) {
                cout << "Warning: " << __FUNCTION__ << ":" << __LINE__ << "->" << "List is Empty";
            }
            return;
        }

        DLLNode *freeNode = this->head;

        // one node
        if (this->head == this->tail) {
            assert(this->head->next == nullptr);
            this->head = this->tail = nullptr;
            this->len = this->len - 1;
            assert(this->len == 0);
            delete freeNode;
            return;
        }

        //more than one node;
        DLLNode *temp = this->head->next;
        temp->prev = nullptr;
        if (temp == this->tail) {
            this->head = this->tail = temp;
            this->len = this->len - 1;
            assert(this->len == 1);
        } else {
            this->head = temp;
            this->len = this->len - 1;
        }
        delete freeNode;
        return;
    }

    // remove from tail
    void dequeue() {
        // list is empty
        if (this->head == nullptr) {
            assert(this->len == 0);
            if (this->warn) {
                cout << "Warning: " << __FUNCTION__ << ":" << __LINE__ << "->" << "List is Empty";
            }
            return;
        }

        DLLNode *freeNode = this->tail;

        // one node
        if (this->tail->prev == nullptr) {
            this->head = this->tail = nullptr;
            this->len = this->len - 1;
            assert(this->len == 0);
            return;
        }

        // more than one node
        DLLNode *temp = this->tail->prev;
        temp->next = nullptr;
        if (temp == this->head) {
            this->head = this->tail = temp;
            this->len = this->len - 1;
            assert(this->len == 1);
        } else {
            this->tail = temp;
            this->len = this->len - 1;
        }
        delete freeNode;
        return;
    }
    // remove a data from the list
    void remove(int data) {
        if (this->head == nullptr) {
            assert(this->len == 0);
            if (this->warn) {
                cout << "Warning: " << __FUNCTION__ << ":" << __LINE__ << "->" << "List is Empty";
            }
            return;
        }

        // data is head
        if (this->head->data == data) {
            pop();
            return;
        }

        // data is tail
        if (this->tail->data == data) {
            dequeue();
            return;
        }

        DLLNode *itr = this->head;
        DLLNode *prevNode, *nextNode,  *freeNode;
        prevNode = freeNode = nullptr;
        while ((itr != nullptr) && (itr->data != data)) {
            itr = itr->next;
        }
        if (itr == nullptr) {
            if (this->warn) {
                cout << "Warning: " << __FUNCTION__ << ":" << __LINE__ << "->" << "BOGUS_DATA Data:Data not present in List";
            }
            return;
        }
        freeNode = itr;
        prevNode = itr->prev;
        nextNode = itr->next;
        assert(prevNode != nullptr);
        assert(nextNode != nullptr);
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        this->len = this->len - 1;
        delete freeNode;
        return;
    }

    bool find(int data) {
        int res = false;
        if (this->head == nullptr) {
            assert(this->len == 0);
            if (this->warn) {
                cout << "Warning: " << __FUNCTION__ << ":" << __LINE__ << "->" << "List is Empty";
            }
            return res;
        }
        DLLNode *itr = this->head;
        while ((itr) && (itr->data != data)) {
            itr = itr->next;
        }
        if (itr == nullptr) {
            return res;
        }else {
            res = true;
            return res;
        }
    }

    void free() {
        if (this->head == nullptr) {
            assert(this->len == 0);
            if (this->warn) {
                cout << "Warning: " << __FUNCTION__ << ":" << __LINE__ << "->" << "List is Empty";
            }
            return;
        }
        while (this->head != nullptr) {
            pop();
        }
        assert(this->len == 0);
        return;
    }

    int peek() {
        if (this->head == nullptr) {
            assert(this->len == 0);
            if (this->warn) {
                cout << "Warning: " << __FUNCTION__ << ":" << __LINE__ << "->" << "List is Empty";
            }
            return BOGUS_DATA;
        }
        return (this->head->data);
    }

    int bottom() {
        if (this->tail == nullptr) {
            assert(this->len == 0);
            if (this->warn) {
                cout << "Warning: " << __FUNCTION__ << ":" << __LINE__ << "->" << "List is Empty";
            }
            return BOGUS_DATA;
        }
        return (this->tail->data);
    }

    ~DLL() {
        free();
        this->head = nullptr;
        this->len = 0;
    }

    void reverse() {
        if (this->head == nullptr) {
            assert(this->len == 0);
            if (this->warn) {
                cout << "Warning: " << __FUNCTION__ << ":" << __LINE__ << "->" << "List is Empty";
            }
            return;
        }
        if (this->head->next == nullptr) {
            assert(this->len == 1);
            return;
        }

        DLLNode *rev, *prevNode, *itr, *nextNode;
        rev = prevNode = nullptr;
        itr = this->head;
        this->tail = this->head;

        while(itr != nullptr) {
            nextNode = itr->next;
            prevNode = itr->prev;
            /* ---- Mistake happens ----- */
            if (rev != nullptr) {
                rev->prev = itr;
            }
            itr->next = rev;
            rev = itr;

            /* ------ Mistake Happens ---- */
            if (nextNode != nullptr) {
                nextNode->prev = nullptr;
            }

            itr = nextNode;
        }
        this->head = rev;
    }

    DLLNode* Head() {
        if (this->head != nullptr) {
            return this->head;
        } else {
            return nullptr;
        }
    }
    DLLNode* Tail() {
        if (this->tail != nullptr) {
            return this->tail;
        } else {
            return nullptr;
        }
    }

    friend ostream& operator<<(ostream& os, DLL *list);

};

ostream & operator<<(ostream& os, DLL *list) {
    DLLNode *head = list->Head();
    DLLNode *tail = list->Tail();
    os << "--------------------------------------------------------------" << endl;
    if (head == nullptr) {
        assert(tail == nullptr);
        os << "[]" << endl;
        return os;
    }
    os << "[";
    while (head != nullptr) {
        os << head->data << " ";
        head = head->next;
    }
    os << "]" << endl;

    os << "[";
    while (tail != nullptr) {
        os << tail->data << " ";
        tail = tail->prev;
    }
    os << "]" << endl;


    os << "--------------------------------------------------------------" << endl;
    return os;
}

void testDLL(){
    DLL *list = new DLL();
    cout << list << endl;

    for (int i = 0; i < 10; i++) {
        //cout << "Appending " << i << endl;
        list->append(i);
    }

    for (int i = 9; i >=0; i-- ) {
        //cout << "Inserting " << i << endl;
        list->insert(i);
    }

    cout << list << endl;

    list->reverse();
    cout << list;
    /*
    list->reverse();
    cout << list;
     */

    int data = 10;
    bool ret = list->find(data);
    cout << data << " Exist: " << ret << endl;

    list->pop();
    cout << list;

    list->dequeue();
    cout << list;

    data = 8;
    list->remove(data);
    cout << list;

}

#endif //GNU_DLL_H
