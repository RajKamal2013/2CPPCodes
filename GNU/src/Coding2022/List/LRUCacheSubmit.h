//
// Created by Raj Kamal on 15/08/22.
//

#ifndef GNU_LRUCACHESUBMIT_H
#define GNU_LRUCACHESUBMIT_H


#include <iostream>
#include <map>
#include <string>
using namespace std;

// Do not edit the class below except for the insertKeyValuePair,
// getValueFromKey, and getMostRecentKey methods. Feel free
// to add new properties and methods to the class.

class DListNode {
public:
    string key;
    int value;
    DListNode *next;
    DListNode *prev;

    DListNode(string key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
public:
    int maxSize;
    DListNode *head;
    map<string, DListNode *> hashTable;

    LRUCache(int maxSize) {
        this->maxSize = maxSize > 1 ? maxSize : 1;
        this->head = nullptr;
        this->hashTable.clear();
    }

    void insertAtHead(string key, int value) {
        DListNode *newNode = new DListNode(key, value);
        newNode->key = key;
        newNode->value = value;
        if (this->head != nullptr) {
            this->head->prev = newNode;
        }
        newNode->next = this->head;
        this->head = newNode;
    }

    string removeAtTail() {
        DListNode *tail = this->head;
        while(tail->next != nullptr) {
            tail = tail->next;
        }
        tail->prev->next = nullptr;
        string key = tail->key;
        delete tail;
        return key;
    }

    ~LRUCache() {
        DListNode *curr = this->head;
        DListNode *temp = nullptr;
        while(curr != nullptr) {
            temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void fixNode(DListNode *node, int value) {
        /* Node is head */
        if (this->head->key == node->key) {
            this->head->value = value;
            return;
        }

        /* Node is tail */
        DListNode *prevNode, *nextNode;
        if (node->next == nullptr) {
            prevNode = node->prev;
            prevNode->next = nullptr;
            node->prev = nullptr;
            node->next = this->head;
            this->head = node;
            return;
        }
        /* Node is somewhere else */
        prevNode = node->prev;
        nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        this->head->prev = node;
        node->next = this->head;
        this->head = node;

        return;
    }

    void insertKeyValuePair(string key, int value) {
        if (hashTable.find(key) == hashTable.end()) {
            // size exceeded, need to eject.
            if (hashTable.size() == this->maxSize) {
                string oldkey = removeAtTail();
                hashTable.erase(hashTable.find(oldkey));
            }
            insertAtHead(key, value);
            hashTable[key] = this->head;
            //hashTable.insert(pair<string, DListNode*>(key, this->head));
            return;
        }
        // key exists
        DListNode *curr =  hashTable[key];
        fixNode(curr, value);
        return;
    }

    int *getValueFromKey(string key) {
        if (this->head == nullptr) {
            return nullptr;
        }

        if (hashTable.find(key) != hashTable.end()) {
            DListNode *curr = hashTable[key];
            int value = curr->value;
            fixNode(curr, value);
            return &(this->head->value);
        } else {
            return nullptr;
        }
    }

    string getMostRecentKey() {
        if (this->head == nullptr) {
            return "";
        } else {
            return this->head->key;
        }
    }

    friend ostream& operator<<(ostream& os, const LRUCache& cache);
};

ostream& operator<<(ostream& os, const LRUCache& cache) {
    DListNode *dll =  cache.head;
    os << endl;
    os << "---------------------------------------------------------------------------" << endl;
    os << "DLL :" << endl;
    while (dll != nullptr) {
        os << dll->key << "-" << dll->value << endl;
        dll = dll->next;
    }
    os << "HashTable: " << endl;
    for (auto it = cache.hashTable.begin(); it != cache.hashTable.end(); ++it) {
        os << it->first << " = " << it->second->key << " " << it->second->value << endl;
    }
    os << "---------------------------------------------------------------------------" << endl;
    return os;
}

void TestLRUCache() {
        int size = 3;
        string key;
        int value;
        int *valPtr;
        LRUCache *cache = nullptr;

        /*
        cache = new LRUCache(size);

        cache->insertKeyValuePair("a", 1);
        cout<<"Cache: " << *cache << endl;
        cache->insertKeyValuePair("b", 2);
        cout<<"Cache: " << *cache << endl;
        cache->insertKeyValuePair("c", 3);
        cout << endl;
        cout<<"Cache: " << *cache << endl;
        cache->insertKeyValuePair("d", 4);
        cout << endl;
        cout<<"Cache: " << *cache << endl;

        key = cache->getMostRecentKey();
        cout << "Most Recently Key: " << key << endl;
        cout << endl;
        cout<<"Cache: " << *cache << endl;

        key = "a";
        valPtr = cache->getValueFromKey(key);
        if (valPtr == nullptr) {
            cout << "Key: " << key << " does not exists" << endl;
        } else {
            cout << "Key Exists: " << key << ":" << *valPtr << endl;
        }
        cout << endl;
        cout<<"Cache: " << *cache << endl;


        key = cache->getMostRecentKey();
        cout << "Most Recently Key: " << key << endl;
        cout << endl;
        cout<<"Cache: " << *cache << endl;

        key = "d";
        value = 4;
        cache->insertKeyValuePair(key, value);
        cout << endl;
        cout<<"Cache: " << *cache << endl;

        key = "b";
        valPtr = cache->getValueFromKey(key);
        if (valPtr == nullptr) {
            cout << "Key: " << key << " does not exists" << endl;
        } else {
            cout << "Key Exists: " << key << ":" << *valPtr << endl;
        }
        cout << endl;
        cout<<"Cache: " << *cache << endl;

        key = "a";
        value = 5;
        cache->insertKeyValuePair(key, value);
        cout << endl;
        cout<<"Cache: " << *cache << endl;

        key = "a";
        valPtr = cache->getValueFromKey(key);
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
        cout<<"Cache: " << *cache << endl;
        delete cache;
        */

        cout << "-------------------------------------------------------" << endl;
        cache = new LRUCache(1);

        key = "a";
        value = 1;
        cache->insertKeyValuePair(key, value);
        cout << cache;

        key = "a";
        value = 9001;
        cache->insertKeyValuePair(key, value);
        cout << cache;

        key = "b";
        value = 2;
        cache->insertKeyValuePair(key, value);
        cout << cache;

        key = "c";
        value = 3;
        cache->insertKeyValuePair(key, value);
        cout << cache;

        delete cache;

}


#endif //GNU_LRUCACHESUBMIT_H
