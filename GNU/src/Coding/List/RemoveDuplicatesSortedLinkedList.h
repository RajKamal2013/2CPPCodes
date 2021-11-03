//
// Created by kamr on 11/2/2021.
//

#ifndef GNU_REMOVEDUPLICATESSORTEDLINKEDLIST_H
#define GNU_REMOVEDUPLICATESSORTEDLINKEDLIST_H

SingleLinkedList*
remove_duplicates_in_SingleLinkedList(SingleLinkedList *list) {
    Node *prev, *curr;

    curr = list->getHead();

    if (curr == nullptr) {
        return nullptr;
    }

    while (curr->next != nullptr) {
        if ((prev )&& (prev->value == curr->value)) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    if ((curr != nullptr) && (prev != nullptr) && (curr->value == prev->value)) {
        prev->next = curr->next;
    }
    return list;
}

void
test_remove_duplictes_in_SingleLinkedList()
{
    vector<int> inputs;
    SingleLinkedList *list = new SingleLinkedList();
    int dataToInsert, dataToRemove, dataToSearch, dataToAppend, data;
    Node *nodeToInsert, *nodeToRemove, *nodeToSearch, *nodeToAppend;
    bool nodeFound = false;

    data = 1;
    nodeToInsert = new Node(data);
    list->setHead(nodeToInsert);
    inputs = {1,1,1, 2, 2, 3, 3, 3, 3, 3, 4, 5, 6, 6, 6,6,  7, 8, 8, 8};
    for (auto &data:inputs) {
        nodeToAppend = new Node(data);
        list->append(nodeToAppend);
    }

    List_Display(list->getHead());

    remove_duplicates_in_SingleLinkedList(list);
    List_Display(list->getHead());


}
#endif //GNU_REMOVEDUPLICATESSORTEDLINKEDLIST_H
