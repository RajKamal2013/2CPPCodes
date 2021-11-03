//
// Created by kamr on 11/2/2021.
//

#ifndef GNU_SUMOFLISTS_H
#define GNU_SUMOFLISTS_H



LinkedList *
sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {

    LinkedList *sumOfList = nullptr;
    bool errLog, dbgLog;
    errLog = false;
    dbgLog = false;

    LinkedList *l1, *l2, *curr;
    l1 = linkedListOne;
    l2 = linkedListTwo;

    /* both are null */
    if ((l1 == nullptr) && (l2 == nullptr)) {
        if (errLog) {
            cout << __LINE__ << " ->" << "Both the list are null " << endl;
        }
        return nullptr;
    }

    /* l2 is null, return l1 */
    if (l1 == nullptr) {
        sumOfList = new LinkedList(l2->value);
        curr = sumOfList;
        l2 = l2->next;
        while (l2 != nullptr) {
            curr->next = new LinkedList(l2->value);
            curr = curr->next;
            l2 = l2->next;
        }
        if (errLog) {
            cout << __LINE__ << " ->" << "l1 is null, returning copy of l2 " << endl;
        }
        return sumOfList;
    }

    /* l2 is null, return l1 */
    if (l2 == nullptr) {
        sumOfList = new LinkedList(l1->value);
        curr = sumOfList;
        l1 = l1->next;
        while (l1 != nullptr) {
            curr->next = new LinkedList(l1->value);
            curr = curr->next;
            l1 = l1->next;
        }
        if (errLog) {
            cout << __LINE__ << " ->" << "l2 is null, returning copy of l1 " << endl;
        }
        return sumOfList;
    }

    if(dbgLog) {
        cout << __LINE__ << " ->" << "Both list are not null " << endl;
    }

    /* normal case, both are not null */
    int sum, carry;
    sum = l1->value + l2->value;
    if (sum >= 10) {
        carry = 1;
        sum = sum - 10;
    }
    sumOfList = new LinkedList(sum);
    l1 = l1->next;
    l2 = l2->next;
    curr = sumOfList;

    while ((l1 != nullptr) && (l2 != nullptr)) {
        sum = l1->value + l2->value + carry;
        if (dbgLog) {
            cout << "Sum : "<< sum << endl;
        }
        if (sum >= 10) {
            carry = 1;
            sum = sum - 10;
            if (dbgLog) {
                cout << "Sum : "<< sum  << " Carry: " << carry << " NodeValue " << sum << endl;
            }
        } else {
            carry = 0;
        }
        curr->next = new LinkedList(sum);
        curr = curr->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    /* l2 is smaller number, we need to add the remaining of l1 to sum   */
    while (l1 != nullptr) {
        if (dbgLog) {
            cout << __LINE__ << " -> " << "l2 is smaller number and now adding the carry to l1 " << endl;
        }
        sum = l1->value  + carry;
        if (sum >= 10) {
            carry = 1;
            sum = sum - 10;
        } else {
            carry = 0;
        }
        curr->next = new LinkedList(sum);
        curr = curr->next;
        l1 = l1->next;
    }

    /* l1 is smaller number, we need to add the remaining of l2 to sum   */
    while (l2 != nullptr) {
        if (dbgLog) {
            cout << __LINE__ << " -> " << "l1 is smaller number and now adding the carry to l2 " << endl;
        }
        sum = l2->value  + carry;
        if (sum >= 10) {
            carry = 1;
            sum = sum - 10;
        } else {
            carry = 0;
        }
        curr->next = new LinkedList(sum);
        curr = curr->next;
        l2 = l2->next;
    }
    /* ----------------- Check the carry --------------------- */
    if (carry == 1) {
        curr->next = new LinkedList(carry);
    }

    if (errLog) {
        cout << __LINE__ << "-> " << "Computed the sum of two list " << endl;
    }

    return sumOfList;
}

void
test_sumofLists() {
    LinkedList *l1, *l2, *lSum;
    vector<int> num1 = {};
    vector<int> num2 = {};
    vector<int> res;
    LinkedList *list = {};

    l1 = new LinkedList(2);
    num1 = {4, 7, 1};
    l2 = new LinkedList(9);
    num2 = {4, 5};
    l1->addMany(num1);
    l2->addMany(num2);
    lSum = sumOfLinkedLists(l1, l2);
    cout << "Input" << endl;
    cout << "L1 : " ;
    res.clear();
    res= l1->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
    cout << "L2 : " ;
    res.clear();
    res= l2->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();

    cout << "Output <sum> " << endl;
    cout << "LSum : " ;
    res.clear();
    res= lSum->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();

    cout << "------------------------------------------------------------";
    l1 = new LinkedList(2);
    num1 = {2};
    l2 = new LinkedList(9);
    num2 = {9};
    l1->addMany(num1);
    l2->addMany(num2);
    lSum = sumOfLinkedLists(l1, l2);
    cout << "Input" << endl;
    cout << "L1 : " ;
    res.clear();
    res= l1->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();
    cout << "L2 : " ;
    res.clear();
    res= l2->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();

    cout << "Output <sum> " << endl;
    cout << "LSum : " ;
    res.clear();
    res= lSum->getNodesInArray();
    for (auto &data:res) {
        cout << data << " ";
    }
    cout << endl;
    res.clear();


}
#endif //GNU_SUMOFLISTS_H

/*
    List1 -> 2->4->7->1   -> number -> 1742
    List2 -> 9->4->5      -> number -> 549
    sum -> 1742 + 549 -> 2291
    Output -> 1->9->2->2
*/