//
//Find loop in the linked list. 
// Algorithm  
//Created by kamr on 11/2/2021.
//

#ifndef GNU_LOOP_H
#define GNU_LOOP_H

LinkedList *
findLoop(LinkedList *head) {
    bool dbgLog = true;
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        return nullptr;
    }


    LinkedList *first, *second;
    bool isLoop = false;
    first = second = head;

    while ((first != nullptr) && (second != nullptr)) {
        first = first->next;
        second = second->next;
        if (second->next) {
            second = second->next;
        }
        if (first == second) {
            isLoop = true;
            break;
        }
    }

    if (dbgLog) {
        if (isLoop) {
            cout << "Loop exist " << endl;
        } else {
            cout << "No Loop Exist" << endl;
        }
    }
    LinkedList *nodeInLoop = first;
    int loopSize = 1;
    if (isLoop) {
        while (first->next != nodeInLoop) {
            loopSize = loopSize + 1;
            first = first->next;
        }
        if (dbgLog) {
            cout << "Size of loop:" << loopSize << endl;
        }
        /* use 2 pointer technique to find nodes at distance k. if the k+1 node is same, the first is the cycle . */
        first = head;
        int pos = 1;
        while (true) {
            second = first;
            pos = 1;
            /* get the kth node */
            while (pos < loopSize) {
                second = second->next;
                pos = pos + 1;
            }
            /* if k+1 node is first , we have cycle */
            if (second->next == first) {
                break;
            }
           first = first->next;
        }
        if (dbgLog) {
            cout << "First ptr : " << first->value << endl;
            cout << "Second ptr : " << second->value << endl;
        }
        return first;
    } else {
        return nullptr;
    }
}

void
test_loop() {
    LinkedList *list = new LinkedList(1);
    vector<int> input = {2, 3, 4, 5, 6, 7, 8, 9};
    list->addMany(input);
    vector<int> res ;
    res = list->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;

    int k = 2;
    LinkedList *loop = list->getNthNode(k);
    cout << k << "th Node " << loop->value << endl;
    list->getNthNode(9)->next = list->getNthNode(5);
    loop = findLoop(list);
    cout << "head of loop:" << loop->value << endl;

}
#endif //GNU_LOOP_H
