//
// Created by Raj Kamal on 08/06/22.
//

#ifndef GNU_LINKEDLIST_H
#define GNU_LINKEDLIST_H

#include <iostream>
using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value) {
        this->value = value;
        next = nullptr;
    }
};

LinkedList* append(LinkedList *head, int value) {
    LinkedList *newNode = new LinkedList(value);
    newNode->next = nullptr;

    LinkedList *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

LinkedList* appendList(LinkedList *head, std::vector<int> arr) {
    LinkedList *tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    int idx = 0;
    while (idx < arr.size()) {
        LinkedList *newNode = new LinkedList(arr[idx]);
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
        idx = idx + 1;
    }
    return head;
}

void displayList(LinkedList *head) {
    LinkedList *temp = head;
    while (temp != nullptr) {
        std::cout << temp->value  << " ";
        temp = temp->next;
    }
    std::cout << endl;
}

#endif //GNU_LINKEDLIST_H
