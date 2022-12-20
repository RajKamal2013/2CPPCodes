//
// Created by Raj Kamal on 08/06/22.
//

#ifndef GNU_MERGELIST_H
#define GNU_MERGELIST_H


#include <vector>
#include "LinkedList.h"
#include <iostream>
using namespace std;

/*
 * --------------------------------------- Merge Two List -------------------------------
Merge Two Linked List
    Write a function that takes the head of two sorted list, function should merge the linked
    list in place (should not create new one)
    Input:
            headOne : 2 -> 6 -> 7 -> 8
            headTwo : 1 -> 3 -> 4 -> 5 -> 9 -> 10
    Output:
            1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
 */



/*
 * ----------------------------------PseudoCode ----------------------------------------
 *
 * Two Pointer Technique
            itr1 -> List1
            itr2 -> List2

            // Null checks
            if (list1 is null) and (list2 is  null)  return null
            if list1 is null then return list2
            if list2 is null then return list1

            //Set the head of the merge list to be smaller one
            if (itr1->data < itr2->data)
                    head <- itr1
                    itr1 <- itr1 -> next
            } else {
                    head <- itr2;
                    itr2 <- itr2->next
            }

            // update pointer
            ptr <- head
            ptr->next = null

            // arrange pointer in place (using merge sort technique)
            while (itr1 != null) || (itr2 != null) {
                if (itr1->data <= itr2->data) {
                     itr->next = itr1->next
                     itr1 = itr1->next;
                     itr->next = null
                } else {
                     itr->next = itr1->next
                     itr2 = itr2->next;
                     itr->next = null
                }
            }

            //list1 is not empty yet
            if (itr1 != null) {
                itr->next = itr1->next
                itr1 = itr1->next;
                itr->next = null
            }

            //list2 is not empty yet
            if (itr2 != null) {
               itr->next = itr1->next
               itr2 = itr2->next;
               itr->next = null
            }

            retun head
*/


/*
 * ----------------------------------- List APIs -----------------------------------
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

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
    LinkedList *itr1, *itr2, *head, *itr;

    /* NullChecks */
    if ((headOne == nullptr) && (headTwo == nullptr)) {
        return nullptr;
    }
    if (headOne == nullptr) {
        return headTwo;
    }
    if (headTwo == nullptr) {
        return headOne;
    }

    itr1 = headOne;
    itr2 = headTwo;

    // Find the smaller head
    if (headOne->value < headTwo->value) {
        head = headOne;
        itr1 = itr1->next;
    } else {
        head = headTwo;
        itr2 = itr2->next;
    }

    itr = head;

    // arrange the pointer
    while ((itr1 != nullptr) && (itr2 != nullptr)) {
        if (itr1->value < itr2->value) {
            itr->next = itr1;
            itr1 = itr1->next;
            itr = itr->next;
        } else {
            itr->next = itr2;
            itr2 = itr2->next;
            itr = itr->next;
        }
    }

    // list1 is still non-empty
    if (itr1 != nullptr) {
        itr->next = itr1;
        itr1 = itr1->next;
        itr = itr->next;
    }

    if (itr2 != nullptr) {
        itr->next = itr2;
        itr2 = itr2->next;
        itr = itr->next;
    }

    return head;

}


void
test_MergeLinkedLists() {
    LinkedList *list1 = new LinkedList(2);
    LinkedList *list2 = new LinkedList(1);

    vector<int> arr1 = {6, 7, 8};
    vector<int> arr2 = {3, 4, 5, 9, 10};
    list1 = appendList(list1, arr1);
    list2 = appendList(list2, arr2);
    std::cout << "Input:" << std::endl;
    std::cout << "List1: ";
    displayList(list1);
    std::cout << "List2: ";
    displayList(list2);

    LinkedList *list = mergeLinkedLists(list1, list2);
    std::cout << "Output:";
    displayList(list);

}
#endif //GNU_MERGELIST_H
