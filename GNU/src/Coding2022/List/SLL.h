//
// Created by Raj Kamal on 28/08/22.
//

#ifndef GNU_SLL_H
#define GNU_SLL_H

#include <iostream>
using namespace std;

const int BOGUS_DATA = INT32_MAX;

struct SLLNode {
    int data;
    SLLNode *next;
};

class SLL {
    SLLNode *head;
    int len;
    bool debug, warn;

public:
    SLL() {
        this->head = nullptr;
        this->len = 0;
        this->warn = this->debug = true;
    }

    // Insert at Beginning
    void insert(int data) {
        SLLNode *newNode = new SLLNode();
        newNode->data = data;
        newNode->next = nullptr;
        //empty list
        if (this->head == nullptr) {
            if (debug) {
                cout << "Empty List" << endl;
            }
            this->head = newNode;
            this->len = this->len + 1;
            return;
        }

        SLLNode *temp = this->head;
        newNode->next = temp;
        this->head = newNode;
        this->len = this->len + 1;
    }
    //Insert at End
    void append(int data) {
        SLLNode *newNode = new SLLNode();
        newNode->data = data;
        newNode->next = nullptr;

        //empty list
        if (this->head == nullptr) {
            if (debug) {
                cout << "Empty List" << endl;
            }
            this->head = newNode;
            this->len = this->len + 1;
            return;
        }

        SLLNode *itr = this->head;
        while (itr->next != nullptr) {
            itr = itr->next;
        }
        itr->next = newNode;
        this->len = this->len + 1;
        return;
    }

    int peek() {
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "Empty List" << endl;
            }
            return BOGUS_DATA;
        }
        return this->head->data;
    }

    int bottom() {
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "Empty List" << endl;
            }
            return BOGUS_DATA;
        }
        SLLNode *itr = this->head;
        while (itr->next != nullptr) {
            itr = itr->next;
        }
        return itr->data;
    }

    // remove head.
    void pop() {
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "Empty List" << endl;
            }
            return;
        }
        //only one node
        SLLNode *freeNode = this->head;
        if (freeNode->next == nullptr) {
            this->head = nullptr;
            this->len = this->len - 1;
            delete freeNode;
            return;
        }
        //more than one node
        SLLNode *nextNode = this->head->next;
        this->head = nextNode;
        this->len = this->len - 1;
        delete freeNode;
    }

    void dequeue() {
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "Empty List" << endl;
            }
            return;
        }
        //only one node
        SLLNode *freeNode = this->head;
        if (freeNode->next == nullptr) {
            this->head = nullptr;
            this->len = this->len - 1;
            delete freeNode;
            return;
        }

        //more than one node
        SLLNode *itr = this->head;
        SLLNode *prevNode = nullptr;
        while (itr->next != nullptr) {
            prevNode  = itr;
            itr = itr->next;
        }
        freeNode = itr;
        prevNode->next = nullptr;
        delete freeNode;
        this->len = this->len - 1;
        return;
    }

    void remove(int data) {
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "Empty List" << endl;
            }
            return;
        }

        // removing head
        if (this->head->data == data) {
            pop();
            return;
        }

        SLLNode *itr = this->head;
        SLLNode *prevNode = nullptr;
        SLLNode *freeNode = nullptr;

        while((itr != nullptr) && (itr->data != data)) {
            prevNode= itr;
            itr = itr->next;
        }
        if (itr == nullptr) {
            if (this->warn) {
                cout << "Data: " << data << " does not exit in List" << endl;
            }
            return;
        }
        freeNode = itr;
        prevNode->next = itr->next;
        delete freeNode;
        this->len = this->len - 1;
        return;
    }

    void free() {
        while (this->head != nullptr) {
            pop();
        }
        assert(this->len == 0);
    }


    bool find(int data) {
        bool res = false;
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "Empty List" << endl;
            }
            return res;
        }
        SLLNode *itr = this->head;
        while ((itr != nullptr) && (itr->data != data)) {
            itr = itr->next;
        }
        if (itr == nullptr) {
            return res;
        } else {
            res = true;
            return res;
        }
    }

    void reverse() {
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "Empty List" << endl;
            }
            return;
        }

        // only one element
        if (this->head->next == nullptr) {
            return;
        }

        //more than one element
        SLLNode *rev, *nextNode, *itr;
        rev = nextNode = nullptr;
        itr = this->head;
        while(itr != nullptr) {
            nextNode = itr->next;
            itr->next = rev;
            rev = itr;
            itr = nextNode;
        }
        this->head = rev;
    }

    SLLNode* Head() {
        if (this->head == nullptr) {
            if (this->warn) {
                cout << "Empty List" << endl;
            }
        }
        return this->head;
    }

    ~SLL() {
        free();
    }

    friend ostream& operator<<(ostream& os, SLL *list);
};

ostream & operator<<(ostream& os, SLL *list) {
    SLLNode *head = list->Head();
    os << "--------------------------------------------------------------" << endl;
    if (head == nullptr) {
        os << "[]" << endl;
        return os;
    }
    os << "[";
    while (head != nullptr) {
        os << head->data << " ";
        head = head->next;
    }
    os << "]" << endl;
    return  os;
}

void testSLL(){
    SLL *list = new SLL();
    cout << list << endl;

    for (int i = 0; i < 10; i++) {
        //cout << "Appending " << i << endl;
        list->append(i);
    }

    for (int i = 9; i >=0; i-- ) {
        //cout << "Inserting " << i << endl;
        list->insert(i);
    }

    cout << "-------------------- List ----------------------" << endl;
    cout << list << endl;
    cout << "-------------------- Reverse ----------------------" << endl;
    list->reverse();
    cout << list;
    cout << "-------------------- Re-Reverse ----------------------" << endl;
    list->reverse();
    cout << list;

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

#endif //GNU_SLL_H
