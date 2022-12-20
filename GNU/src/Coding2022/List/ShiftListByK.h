//
// Created by Raj Kamal on 07/06/22.
//

#ifndef GNU_SHIFTLISTBYK_H
#define GNU_SHIFTLISTBYK_H

#include "LinkedList.h"


/*
 * Shift Linked List by K :
	Write  a Program that takes a single Linked List and an integer K, shift
    the list in place by K and returns head (does not create a new list)
	K -> Positive, shift forward
	K -> Negative, shift backward
	Example:-
		Input :-
		List  : 0 ->1 -> 2 -> 3 -> 4 -> 5
		K = 2
		Output :-
		List:   4 -> 5 -> 0 -> 1 -> 2 -> 3
		Input :-
		List :  0 -> 1 -> 2 -> 3 -> 4 -> 5
		K = -2
		Output :-
		List:   2 -> 3 -> 4 -> 5 -> 0 -> 1
 * PseudoCode
 * PseudoCode
1. Find length of list
2. Find newTail -> position to move
       offset  = abs(K) % length
       if K > 0
            offset = length - offset

4. now start shifting
    temp = head
    idx = 0;
    while (idx < offset) {
        temp = head->next;
        end -> next = head;
        head = temp;
        idx = idx + 1;
    }

5. return head
 */

#include <iostream>
using namespace std;

/*
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

LinkedList* appendList(LinkedList *head, vector<int> arr) {
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
*/

LinkedList *shiftLinkedList(LinkedList *head, int k) {
    bool debug = false;
    LinkedList  *tail, *temp;
    int listLength = 0;
    temp = head;
    listLength = 1;


    while (temp->next != nullptr) {
        temp = temp->next;
        listLength = listLength + 1;
    }
    tail = temp;

    int offset = abs(k) % listLength;

    if (offset == 0) {
        return head;
    }

    if (k < 0) {
        offset = offset;
    } else {
        offset = listLength - offset;
    }

    int idx = 0;
    while (idx < offset) {
        temp = head->next;
        head->next = nullptr;
        tail->next = head;
        tail = tail->next;
        head = temp;
        idx = idx + 1;
    }

    return head;
}

void
test_ShiftLinkedListByK() {
    LinkedList *list = new LinkedList(1);
    int K;
    list = append(list, 2);
    list = append(list, 3);
    vector<int> arr = {4, 5, 6, 7, 8, 9, 10};
    list = appendList(list, arr);
    std::cout << "Input:";
    cout << "1 " << "2 " << "3 ";
    for (auto data: arr) {
        cout << data << " ";
    }
    cout << endl;

    K = 2;
    list = shiftLinkedList(list, K);
    std::cout<<"Shifted List by " << K << endl;
    displayList(list);
}

#endif //GNU_SHIFTLISTBYK_H
