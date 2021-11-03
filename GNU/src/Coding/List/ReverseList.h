//
// Created by kamr on 11/3/2021.
//

#ifndef GNU_REVERSELIST_H
#define GNU_REVERSELIST_H

LinkedList *
reverseLinkedList(LinkedList *head) {
    /* empty list, nothing to do */
    if (head == nullptr) {
        return nullptr;
    }
    /* if one node */
    if (head->next == nullptr) {
        return head;
    }

    /* we keep-> curr, rev, next
     * rev to keep the reverse of list
     * curr point to current pointer in list
     * next -> keep the next to curr
     */
    LinkedList *curr, *next, *rev;
    curr = head;
    /* init these to nullptr */
    next = rev = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        /* curr to the reverse of list */
        curr->next = rev;
        /* update the head pointer of reverse */
        rev = curr;
        curr = next;
    }

    return rev;
}

void
test_reverse() {
    LinkedList *SL1, *list, *rev;
    vector<int> res;
    vector<int> input;

    SL1 = new LinkedList(1);
    input = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    SL1->addMany(input);
    res.clear();
    res = SL1->getNodesInArray();
    rev = reverseLinkedList(SL1);

    cout << "Input" << endl;
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();

    cout<<"Ouput:" << endl;
    res.clear();
    res = rev->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
}

#endif //GNU_REVERSELIST_H
