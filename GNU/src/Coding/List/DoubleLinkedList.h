//
// Created by kamr on 11/1/2021.
//

#ifndef GNU_DOUBLELINKEDLIST_H
#define GNU_DOUBLELINKEDLIST_H

#include <iostream>
#include <vector>
using namespace std;



class Node {
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value);
};

Node::Node(int value) {
    this->value = value;
    prev = nullptr;
    next = nullptr;
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    /*
     * Node *curr = head ;
     * while(curr != nullptr) {
     *  if (curr->value == value) {
     *        ret = true;
     *       break;
     *   }
     *   curr = curr->next;
     *  }
     */
    bool
    containsNodeWithValue(int value) {
        Node *curr = head;
        bool ret = false;
        while(curr != nullptr) {
            if (curr->value == value) {
                ret = true;
                break;
            }
            curr  = curr->next;
        }
        return ret;
    }

    Node*
    contains(int value) {
        Node *curr = head;
        while(curr != nullptr) {
            if (curr->value == value) {
                break;
            }
            curr  = curr->next;
        }
        return curr;
    }

    /*
     * if (node == head)  -> node = node->next;
     * if (node == tail)  -> tail = node->prev;
     * if (node->prev != nullptr) -> node->prev->next = node->next;
     * if (node->next != nullptr) -> node->next->prev=  node->prev;
     * node->next = nullptr
     * node->prev = nullptr
     */
    void
    remove(Node *node) {
        if (node == head) {
            node = node->next;
            head = node;
        }
        if (node == tail) {
            tail = node->prev;
        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        node->next = node->prev = nullptr;
    }

    /*
     * if (nodeToInsert == head) && (nodeToInsert == tail) then -> nothing. -> one node.
     * remove(nodeToInsert);
     * if (node does not exists in list) -> do nothing. -->
     * nodeToInsert->next = node;
     * nodeToInsert->prev = node->prev;
     * if (node == head)  -> nodeToInsert becomes head
     * else node->prev->next = nodeToInsert;
     * node->prev = nodeToInsert
     */

    void
    insertBefore(Node *node, Node *nodeToInsert) {
        if ((nodeToInsert == head) && (nodeToInsert == tail)) {
            return;
        }
        remove(nodeToInsert);
        /* pointer management */
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;
        if(node->prev == nullptr) {
            head = nodeToInsert;
        } else {
            node->prev->next = nodeToInsert;
        }
        node->prev = nodeToInsert;
    }

    /*
     * if (nodeToInsert == head) and (nodeToInsert == tail ) -> do nothing
     * remove(nodeToInsert)
     * if (node does not exist in list ) -> do nothing
     * nodeToInsert->prev = node;
     * nodeToInsert->next = node->next;
     * if (node == tail) nodeToInsert->next = nullptr and nodeToInsert becomes tail
     * else node->next->prev = nodeToInsert;
     * node->next = nodeToInsert;
     */
    void
    insertAfter(Node *node, Node *nodeToInsert) {
        if ((nodeToInsert == head) && (nodeToInsert == tail)) {
            return;
        }
        remove(nodeToInsert);
        // change the pointers
        nodeToInsert->prev  = node;
        nodeToInsert->next = node->next;
        if (node->next == nullptr) {
            tail = nodeToInsert;
        } else {
            node->next->prev = nodeToInsert;
        }
        node->next = nodeToInsert;
    }

    /*
     * if (head is null) then head = tail = node.
     * else remove(node) -> if exits  ->
     * node->next = head;
     * head->prev = node;
     * head = node;
     */
    void
    setHead(Node *node) {
        if (head == nullptr) {
            head = node;
            tail = node;
            return;
        }
        insertBefore(head, node);
    }

    /*
     * if (tail is null) then head  = tail = node
     * else remove(node) -> if exists ->
     * tail->next = node;
     * node->prev = tail;
     * tail = node;
     */
    void
    setTail(Node *node) {
        if (tail == nullptr) {
            head = tail = node;
            return;
        }
        insertAfter(tail, node);
    }

    /*
     * if (position == 1)  -> setHead(nodeToInsert)
     * Node *curr = head;, pos = 0;
     * while (pos != position) {
     * curr = curr->next;
     * pos++
     *}
     *
     * if (node == nullptr) -> setTail(nodeToInsert)
     * else insertBefore(curr, nodeToInsert);
     */

    void
    insertAtPosition(int position, Node *nodeToInsert) {
        if (position == 1) { setHead(nodeToInsert); return;}
        int pos = 1;
        Node *curr = head;
        while ((curr != nullptr) && (pos != position )) {
            curr = curr->next;
            pos++;
        }
        if(curr != nullptr) {
            insertBefore(curr, nodeToInsert);
        } else {
            setTail(nodeToInsert);
        }
    }

    /*
     * Node *curr = head;
     * while (curr != nullptr) {
     *    if (curr->value == value) {
     *      nodeToRemove = curr->next;
     *      curr = curr->next;
     *      remove(nodeToRemove);
     *   } else {
     *     curr = curr->next;
     *   }
     * }
     */
    void
    removeNodesWithValue(int value) {
        Node *curr = head;
        Node *nodeToRemove = nullptr;
        /* Remove Duplicates */
        while (curr != nullptr) {
            if (curr->value == value) {
                nodeToRemove = curr;
                curr = curr->next;
                remove(nodeToRemove);
            } else {
                curr = curr->next;
            }
        }
    }

    void display() {
        Node *curr = head;
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

void
test_DoubleLinkedList() {
    Node *node, *newNode;
    DoublyLinkedList *list = new DoublyLinkedList();
    vector<int>input = {2, 3, 4, 5};

    int prev = 1;
    newNode = new Node(1);
    list->setHead(newNode);
    for (auto &data:input) {
        node = list->contains(prev);
        newNode = new Node(data);
        list->insertAfter(node, newNode);
        prev = data;
    }
    list->display();

    int val = 5;
    node = list->contains(val);
    if (node != nullptr) {
        cout << "Node <" << val << " >" << "Exists" << endl;

    }
    list->remove(node);
    list->display();
}

/*
Assume I have list
1 <-> 2 <-> 3 <-> 4 <-> 5

StandAlone Nodes -> 3, 3, 6

setHead(4) ->
    Input  ->  1 <-> 2 <-> 3 <-> 4 <-> 5
    Output ->  4 <-> 1 <-> 2 <-> 3 <-> 5

setTail(6) ->
    Input  -> 4 <-> 1 <-> 2 <-> 3 <-> 5
    Output -> 4 <-> 1 <-> 2 <-> 3 <-> 5 <-> 6

// Insert node 3 before 6  -> move existing node before 6
insertBefore(6, 3) ->
    Input  -> 4 <-> 1 <-> 2 <-> 3 <-> 5 <-> 6
    Output -> 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6

insertAfter(6, 3) ->  // Add standAlone node 3 after 6
    Input  -> 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6
    Output -> 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6 <-> 3

insertAtPosition(1, 3) -> // Insert a standAlone node with Value 3 in front of 1
    Input ->  4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6 <-> 3
    Output -> 3 <-> 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6 <-> 3

removeNodesWithValue(3) -> // Insert all nodes with value 3
    Input ->  3 <-> 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6 <-> 3
    Output -> 4 <-> 1 <-> 2 <-> 5 <-> 6

remove(2)  Remove node with value 2
    Input ->  4 <-> 1 <-> 2 <-> 5 <-> 6
    Output -> 4 <-> 1 <-> 5 <-> 6

containsNodeWithValue(5)
    Input ->  4 <-> 1 <-> 5 <-> 6
    Output -> true
*/

#endif //GNU_DOUBLELINKEDLIST_H
