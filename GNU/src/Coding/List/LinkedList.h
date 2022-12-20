//
// Created by kamr on 11/2/2021.
//

#ifndef GNU_LINKEDLIST_H
#define GNU_LINKEDLIST_H


#include <iostream>
#include <vector>
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next;
    LinkedList *tail;

    LinkedList(int value) {
        this->value = value;
        this->next = nullptr;
    }

    LinkedList *
    insert(int value) {
        LinkedList *current = this;
        LinkedList *newNode = new LinkedList(this->value);
        if (current->next != nullptr) {
            newNode->next = current->next;
        }
        current->next = newNode;
        current->value = value;
        return this;
    }

    LinkedList *append(int value) {
        LinkedList *current = this;

        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new LinkedList(value);
        return this;
    }

     LinkedList *
     addMany(vector<int> values) {
        LinkedList *current = this;
        while (current->next != nullptr) {
            current = current->next;
        }
        for (auto value : values) {
            current->next = new LinkedList(value);
            current = current->next;
        }
        return this;
    }

    /*
    void addMany(vector<int> values) {
        LinkedList *newNode;
        LinkedList *curr;
        for (auto &data : values) {
            newNode = new LinkedList(data);
            curr = this;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    */
    vector<int> getNodesInArray() {
        vector <int> res;
        LinkedList *curr = this;
        while (curr != nullptr) {
            res.push_back(curr->value);
            curr = curr->next;
        }
        return res;
    }

    LinkedList *getNthNode(int n) {
        int counter = 1;
        LinkedList *current = this;
        while (counter < n) {
            current = current->next;
            counter++;
        }
        return current;
    }
};

void
test_LinkedList() {
    LinkedList* list;
    vector <int> arr;
    vector <int> res = {};

    cout << "------------------------------------------" << endl;
    LinkedList *SL1 = new LinkedList(0);
    list = SL1;
    arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list->addMany(arr);
    res.clear();
    res = list->getNodesInArray();
    cout << "Input" << endl;
    for (auto &data:arr) {
        cout << data << " ";
    }
    cout << endl;
    cout << "Output" << endl;
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();

    list->insert(-1);
    res.clear();
    res = list->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();

    list->append(10);
    res.clear();
    res = list->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();


}



#endif //GNU_LINKEDLIST_H
