//
// Created by Raj Kamal on 28/08/22.
//

#ifndef GNU_CLL_H
#define GNU_CLL_H

#include <iostream>
using namespace std;
struct CLLNode {
    int data;
    CLLNode *next;
};

int const BOGUS_DATA = INT32_MAX;

class CLL {
    CLLNode *head;
    CLLNode *tail;
    int len;
    bool debug, warn;

public:
    CLL() {
        this->head = nullptr;
        this->tail = nullptr;
        this->len = 0;
        this->warn = this->debug = true;
    }

    CLLNode* Head() {
        if (this->head == nullptr) {
            if (this->debug) {
                cout << "List is Empty" << endl;
            }
        }
        return  this->head;
    }

    CLLNode* Tail() {
        if (this->tail == nullptr) {
            if (this->debug) {
                cout << "List is Empty" << endl;
            }
        }
        return this->tail;
    }

    void insert(int data) {
        CLLNode *newNode = new CLLNode();
        newNode->data = data;
        newNode->next= nullptr;

        if (this->head == nullptr) {
            if (this->debug) {
                cout << "List is Empty" << endl;
            }
            this->head = this->tail = newNode;
            newNode->next = this->head;
            this->len = this->len + 1;
            return;
        }
        CLLNode *temp = this->head;
        newNode->next = temp;
        this->head = newNode;
        this->tail->next = newNode;
        this->len = this->len + 1;
        return;
    }

    // append
    void append(int data) {
        CLLNode *newNode = new CLLNode();
        newNode->data = data;
        newNode->next= nullptr;

        if (this->head == nullptr) {
            if (this->debug) {
                cout << "List is Empty" << endl;
            }
            this->head = this->tail = newNode;
            newNode->next = this->head;
            this->len = this->len + 1;
            return;
        }

        CLLNode *temp = this->tail;
        temp->next = newNode;
        newNode->next = this->head;
        this->tail = newNode;
        this->len = this->len + 1;
        return;
    }

    int peek() {
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "List is Empty" << endl;
            }
            return BOGUS_DATA;
        }
        return this->head->data;
    }

    int bottom() {
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "List is Empty" << endl;
            }
            return BOGUS_DATA;
        }
        return this->tail->data;
    }

    // remove the head
    void pop() {
        //empty list
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "List is Empty" << endl;
            }
            return;
        }

        //one element;
        CLLNode *freeNode = this->head;
        if (this->head == this->tail) {
            this->head = this->tail = nullptr;
            delete freeNode;
            this->len = this->len - 1;
            return;
        }

        //more than one element
        CLLNode *temp = this->head;
        this->tail->next = temp->next;
        this->head = temp->next;
        delete temp;
        this->len = this->len - 1;
        return;
    }

    // remove tail
    void dequeue() {
        //empty list
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "List is Empty" << endl;
            }
            return;
        }

        //one element;
        CLLNode *freeNode = this->head;
        if (this->head == this->tail) {
            this->head = this->tail = nullptr;
            delete freeNode;
            this->len = this->len - 1;
            return;
        }

        CLLNode *itr = this->head;
        CLLNode *prevNode = nullptr;
        while (itr->next != this->head) {
            prevNode = itr;
            itr = itr->next;
        }
        freeNode = itr;
        prevNode->next = this->head;
        this->tail = prevNode;
        delete freeNode;
        this->len = this->len - 1;
        return;
    }

    void remove(int data) {
        //empty list
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "List is Empty" << endl;
            }
            return;
        }

        //remove head
        if (this->head->data == data) {
            pop();
            return;
        }
        //remove tail
        if (this->tail->data == data) {
            dequeue();
            return;
        }

        CLLNode *itr, *prevNode;
        itr = this->head->next;
        while ((itr != this->head)  && (itr->data != data)) {
            prevNode = itr;
            itr = itr->next;
        }
        if (itr == this->head) {
            if (this->warn) {
                cout << "Data: " <<data << " does not exist in list" << endl;
            }
            return;
        }
        CLLNode *freeNode = itr;
        prevNode->next = itr->next;
        delete freeNode;
        this->len = this->len - 1;
        return;
    }

    bool find(int data) {
        bool res = false;
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "List is Empty" << endl;
            }
            return res;
        }
        CLLNode *itr = this->head;
        if (itr->data == data) {
            res = true;
            return res;
        }
        itr = itr->next;
        while ((itr != this->head) && (itr->data != data)) {
            itr = itr->next;
        }
        if (itr == this->head) {
            return res;
        }
        res = true;
        assert(itr->data == data);
        return res;
    }

    void free() {
        while (this->head != nullptr) {
            pop();
        }
    }

    ~CLL() {
        free();
    }

    friend ostream& operator<<(ostream& os, CLL *list);

};

ostream& operator<<(ostream& os, CLL *list) {
    CLLNode *head = list->Head();
    os << "--------------------------------------------------------------" << endl;
    if (head == nullptr) {
        os << "[]" << endl;
        return os;
    }
    os << "[";
    os << head->data << " ";
    head = head->next;
    while (head != list->Head()) {
        os << head->data << " ";
        head = head->next;
    }
    os << "]" << endl;
    return  os;
}

void testCLL(){
    CLL *list = new CLL();
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

    cout << "-------------------- List ----------------------" << endl;
    cout << list << endl;


    int data = 10;
    cout << "----------- Searching " << data << "----------------" << endl;
    bool ret = list->find(data);
    cout << data << " Exist: " << ret << endl;

    data = list->peek();
    cout << "----------- Remove " << data << "----------------" << endl;
    list->pop();
    cout << list;

    data = list->bottom();
    cout << "----------- Remove " << data << "----------------" << endl;
    list->dequeue();
    cout << list;

    data = 8;
    cout << "----------- Remove " << data << "----------------" << endl;
    list->remove(data);
    cout << list;


    data = 5;
    cout << "----------- Remove " << data << "----------------" << endl;
    list->remove(data);
    cout << list;

 }

#endif //GNU_CLL_H
