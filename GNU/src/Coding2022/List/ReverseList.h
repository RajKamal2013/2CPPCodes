//
// Created by Raj Kamal on 12/06/22.
//

#ifndef GNU_REVERSELIST_H
#define GNU_REVERSELIST_H

#include "LinkedList.h"
#include <vector>

/*
 * Write function that takes the head of list and reverses the list in place
 * Input:
 *      Head: 0 -> 1 -> 2 -> 3 -> 4 -> 5
 * Output :
 *      5 -> 4 -> 3 -> 2 -> 1 -> 0
 *
 *
 *
 */

LinkedList *reverseLinkedList(LinkedList *head) {
    // list is empty or has only one element
    if ((head == nullptr) || (head->next == nullptr)) {
        return head;
    }
    // list has more than one element
    LinkedList *curr, *rev, *temp;
    curr = head;
    rev = nullptr;
    temp = nullptr;

    while(curr != nullptr) {
        temp = curr->next;
        curr->next = rev;
        rev = curr;
        curr = temp;
    }
    return rev;
}

void
test_reverseLinkedList() {
    LinkedList *list = new LinkedList(0);
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    appendList(list, arr);

    cout << "Input: " ;
    displayList(list);

    list = reverseLinkedList(list);
    cout << "Output: <Reverse List>: ";
    displayList(list);
}


#endif //GNU_REVERSELIST_H
