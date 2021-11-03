//
// Created by kamr on 11/2/2021.
//

#ifndef GNU_REMOVEKNODEFROMEND_H
#define GNU_REMOVEKNODEFROMEND_H


void
removeKthNodeFromEnd(LinkedList *head, int k) {
    int count = 0;
    LinkedList *curr = head;
    bool errLog, dbg;
    errLog = true;
    dbg = true;

    if (head == nullptr) {
        if (errLog) {
            cout << __LINE__ << " -> " << "head is null" << endl;
        }
        return;

    }

    /* kth node from last */
    LinkedList *secondPtr;
    secondPtr = head;
    int pos = 1;
    while ((secondPtr != nullptr) &&  ( pos <= k)) {
        secondPtr = secondPtr->next;
        pos = pos + 1;
    }

    /* error case */
    if ((secondPtr == nullptr) && (pos != k+1)) {
        if (errLog) {
            cout << __LINE__ << "-> " << " Kth node does not exist " << endl;
        }
        return;
    }

    if (dbg) {
        if (secondPtr) {
            cout << "Kth " << "<" << k << ">" << "node from start: " << secondPtr->value << endl;
        } else {
            cout << "Reached End of list" << endl;
        }
    }


    /* head case . kth node is tail */
    if (secondPtr == nullptr) {
        curr = head->next;
        head->value = curr->value;
        head->next = curr->next;

        if (errLog) {
            cout << __LINE__ << "-> " << " Kth " << "<" << k << ">" << "node from end is  head: " << curr->value << endl;
        }

        return;
    }


    /* advance two pointers */
    curr = head;
    while (secondPtr->next != nullptr) {
        curr = curr->next;
        secondPtr = secondPtr->next;
    }

    curr->next = curr->next->next;

    return;
}

void
test_removeKthNodeFromEnd() {
    LinkedList* list;
    vector <int> arr;
    vector <int> res = {};
    int k = 4;

    cout << "------------------------------------------" << endl;
    LinkedList *SL1 = new LinkedList(0);
    list = SL1;
    arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list->addMany(arr);
    res.clear();
    res = list->getNodesInArray();
    k = 4;
    removeKthNodeFromEnd(list, k);
    cout << "Input" << endl;
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    cout << "Output" << endl;
    res.clear();
    res = list->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;

    cout << "-----------------------------------------" << endl;
    res.clear();
    res = list->getNodesInArray();
    k = 9;
    removeKthNodeFromEnd(list, k);
    cout << "Input" << endl;
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    cout << "Output" << endl;
    res.clear();
    res = list->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
}

#endif //GNU_REMOVEKNODEFROMEND_H
