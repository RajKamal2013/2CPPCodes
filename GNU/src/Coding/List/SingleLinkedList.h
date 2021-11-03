//
// Created by kamr on 11/1/2021.
//

#ifndef GNU_SINGLELINKEDLIST_H
#define GNU_SINGLELINKEDLIST_H

/*
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
*/
class SingleLinkedList {
    Node *head;
    Node *tail;
    bool log, dbg;

public:
    SingleLinkedList() {
        head = nullptr;
        tail = nullptr;
        log = true;
        dbg = true;
    }

    bool contains(Node *node) {
        Node *curr = head;
        bool nodePresent = false;
        while (curr != nullptr) {
            if (curr == node) {
                nodePresent = true;
                break;
            }
            curr = curr->next;
        }
        return nodePresent;
    }

    Node* getTail() {
        return tail;
    }

    Node* getHead() {
        return head;
    }

    int size() {
        int count = 0;
        Node *curr = head;
        while(curr != nullptr) {
            count = count + 1;
            curr = curr->next;
        }
        return count;
    }

    void insertAfter(Node *node, Node *nodeToInsert) {
        if ((nodeToInsert == head) && (nodeToInsert == tail)) {
            if (log) {
                cout << __LINE__ << " -> " << "Error:Node is both head and tail "<< endl;
            }
            return;
        }
        if (node == tail) {
            nodeToInsert->next = tail->next;
            tail->next = nodeToInsert;
            tail = nodeToInsert;
            return;
        }

        nodeToInsert->next = node->next;
        node->next = nodeToInsert;
    }

    void insertBefore(Node *node, Node *nodeToInsert) {
        if ((nodeToInsert == head) && (nodeToInsert == tail)) {
            if (log) {
                cout << __LINE__ << " -> " << "Error:Node is both head and tail "<< endl;
            }
            return;
        }
        /* We want new node to become head */
        if (node == head) {
            nodeToInsert->next = head;
            head = nodeToInsert;
            if (dbg) {
                cout << __LINE__ << " ->" << "Inserting at head " << endl;
            }
            return;
        }
        Node *curr, *prev;
        curr= head;
        prev = nullptr;
        /* iterate to get the previous */
        while (curr != nullptr) {
            if (curr == node) {
                break;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        if (curr != nullptr) {
            prev->next = nodeToInsert;
            nodeToInsert->next = node;
        } else {
            if (log) {
                cout << __LINE__ << " -> " << "Error:Node: " << node->value << " does not exist" << endl;
            }
        }
    }

    void insertAtPosition(int position, Node *nodeToInsert) {
        if (position == 1) {
            setHead(nodeToInsert);
            return;
        }

        if (head == nullptr) {
            if (log) {
                cout << __LINE__ << " -> " << "Error:Head does not exist" << endl;
            }
            return;
        }

        Node *curr = head;
        Node *prev = nullptr;
        int pos = 1;
        curr = head;
        while ((curr != nullptr) && (pos != position)) {
            prev = curr;
            curr = curr->next;
            pos = pos + 1;
        }

        if (pos == position) {
            prev->next = nodeToInsert;
            if (curr == nullptr) {
                nodeToInsert->next = nullptr;
                tail = nodeToInsert;
            } else {
                nodeToInsert->next = curr;
            }
        } else {
            if (log) {
                cout << __LINE__ << " -> " << "Position:" << position << "is greater then node count " << endl;
            }
        }
    }

    void setHead(Node *newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            if (dbg) {
                cout << __LINE__ << " ->" << "Tail is null" << endl;
            }
            return;
        }
        insertBefore(head, newNode);
    }

    void setTail(Node *newNode) {
        if (tail == nullptr) {
            head = tail = newNode;
            if (dbg) {
                cout << __LINE__ << " ->" << "Tail is null" << endl;
            }
            return;
        }
        insertAfter(tail, newNode);
    }

    void insert(Node *newNode) {
        setHead(newNode);
    }

    void append(Node *newNode) {
        setTail(newNode);
    }

    void remove(Node *nodeToRemove) {
       if (nodeToRemove == head) {
           head = head->next;
           if (head->next == nullptr) {
               head= tail = nullptr;
           }
           return;
       }

       Node *curr, *prev;
       curr = head;
       prev = nullptr;
       while ((curr!= nullptr) && (curr != nodeToRemove)) {
           prev = curr;
           curr = curr->next;
       }
       if (curr == nullptr) {
            if (log) {
                cout << __LINE__  << " -> " << "Node to remove does not exit" << endl;
            }
           return;
       }

       prev->next = curr->next;
       if (curr->next == nullptr) {
           tail = prev;
       }
    }
    /*
    void removeAll(Node *node) {

    }
     */
};


void
List_Display(Node *curr) {
    while (curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

void
test_SingleLinkedList() {
 vector<int> inputs;
 SingleLinkedList *list = new SingleLinkedList();
 int dataToInsert, dataToRemove, dataToSearch, dataToAppend, data;
 Node *nodeToInsert, *nodeToRemove, *nodeToSearch, *nodeToAppend;
 bool nodeFound = false;

 data = 1;
 nodeToInsert = new Node(data);
 list->setHead(nodeToInsert);
 inputs = {2, 3, 4, 5, 6, 7, 8 };
 for (auto &data:inputs) {
     nodeToAppend = new Node(data);
     list->append(nodeToAppend);
 }
 List_Display(list->getHead());
 dataToInsert = 0;
 nodeToInsert = new Node(dataToInsert);
 list->insert(nodeToInsert);
 List_Display(list->getHead());
 dataToAppend = 9;
 nodeToAppend = new Node(dataToAppend);
 list->append(nodeToAppend);
 List_Display(list->getHead());

}
#endif //GNU_SINGLELINKEDLIST_H
