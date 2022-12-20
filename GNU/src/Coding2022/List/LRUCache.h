//
// Created by Raj Kamal on 13/08/22.
//

#ifndef GNU_LRUCACHE_H
#define GNU_LRUCACHE_H

/*
 * Implement LRU Cache class
 * insertkeyValuePair method
 * getValueFromKey method
 * getMostRecentKey method: Retrieve most recently inserted or most recently added.
 *
 * Each of these should run in constant time.
 * LRUCache should store a maxSize property to set the size of cache, which is passed in LRUCache while installing. It represent
 * maximum number of key value pair it can store.
 * If a key value is inserted and cache has already reached it's maximum capacity, then the LeastRecentlyUsed key is ejected.
 * Inserting a key-value that is already existing, existing key should simply replace the value.
 * Attempting to get value for key that does not exist in cache, it should return null.
 */

/*
 * Example:
 * LRUCache(3)
 * insertkeyValuePair("b", 1)
 * insertkeyValuePair("a", 2)
 * insertkeyValuePair("c", 3)
 * getMostRecentKey() -> c
 * getValueFromKey("a") -> 1
 * getMostRecentKey() -> a
 * insertkeyValuePair("d", 4)
 * getValueFromKey("b") : None (already evicted after insertion of d)
 * insertkeyValuePair("a", 5)
 * getValueFromKey("a") -> 5
 */

/*
 * Psuedocode
 * Use 2 data structures to do the coding.
 * Hash Table + Double Linked List
 * Hash Table -> <Key, Double Linked List Node>
 * Double Linked List -> Node {key, value, prev, next}
 *
 *
 * insertKeyValuePair()
 *   // key exists already, update the value
 *   if key exist {
 *      get the Node from hash.
 *      Update the value and move the node to the head of the DLL
 *      return
 *   }
 *   // key does not exist
 *   if maxSize < hash.size() {
 *      add key in hash table
 *      insert at the head of the DLL
 *   } else {
 *       remove the tail of the DLL and the corresponing entry from hash table
 *       create a new node in DLL and add it the head of the DLL
 *       Create a hash entry with key and DLL Node created.
 *   }
 *
 * getMostRecentKey() -> get the head of the list
 *
 * getValueFromKey() ->
 *  if key exists in Hash
 *      Get the Node from hash Table
 *      Move the node to the head of DLL
 *      return the value of the Node.

*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

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
    bool debug = true;

    LRUCache(int maxSize) {
        this->maxSize = maxSize > 1 ? maxSize : 1;
        this->head = nullptr;
        this->hashTable.clear();
        if (debug) {
            cout << __FUNCTION__  << "-> MaxSize: " << this->maxSize << " HashTable Size: " << hashTable.size() << endl;
        }
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
        if (debug) {
            cout << __FUNCTION__ << "->Inserted at Head: " << head << "(" << head->key << ", " << head->value << ")"
                 << endl;
        }
    }

    string removeAtTail() {
        DListNode *tail = this->head;
        string key;
        if (tail->next == nullptr) {
            key = tail->key;
            delete tail;
            this->head = nullptr;
            return key;
        }
        while(tail->next != nullptr) {
            tail = tail->next;
        }
        tail->prev->next = nullptr;
        if (debug) {
            cout << __FUNCTION__ <<"->Removing the Node: " << tail << "(" << tail->key << ", " << tail->value << ")"
                <<endl;
        }
        key = tail->key;
        delete tail;
        return key;
    }

    void fixNode(DListNode *node, int value) {
        /* Node is head */
        if (this->head->key == node->key) {
            if (debug) {
                cout << __FUNCTION__  << "->Node is head" << endl;
            }
            this->head->value = value;
            return;
        }


        /* Node is tail */
        DListNode *prevNode, *nextNode, *headNext;
        if (node->next == nullptr) {
            if (debug) {
                cout << __FUNCTION__ << "->Node is tail" << endl;
            }
            prevNode = node->prev;
            prevNode->next = nullptr;
            node->prev = nullptr;
            this->head->prev = node;
            node->next = this->head;
            this->head = node;
            this->head->value = value;
            return;
        }

        if (debug) {
            cout << __FUNCTION__  << "->Node is somewhere else" << endl;
        }
        /* Node is somewhere else */
        prevNode = node->prev;
        nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        this->head->prev = node;
        node->next = this->head;
        this->head = node;
        this->head->value = value;

        return;
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

    void insertKeyValuePair(string key, int value) {
        if (debug) {
            cout << __FUNCTION__ << "->Inserting: " << key << "-" << value << endl;
        }
        if (hashTable.find(key) == hashTable.end()) {
            // size exceeded, need to eject.
            if (hashTable.size() == this->maxSize) {
                if (debug) {
                    cout << __FUNCTION__ << "->MaxSize Reached. Removing the Tail" << endl;
                }
                string oldkey = removeAtTail();
                hashTable.erase(hashTable.find(oldkey));
            }
            if (debug) {
                cout << __FUNCTION__ << "->Inserting at head: " << key << "-" << value << endl;
            }
            insertAtHead(key, value);
            hashTable[key] = this->head;
            //hashTable.insert(pair<string, DListNode*>(key, this->head));
            return;
        }
        // key exists
        DListNode *curr =  hashTable[key];
        if (debug) {
            cout << __FUNCTION__ << "->Already Exist: " << curr << "(" << curr->key << ", " << curr->value << ")" << endl;
            cout << __FUNCTION__ << "->Fixing the Node" << endl;
        }
        fixNode(curr, value);

        if (debug) {
            cout << __FUNCTION__ << "->New Head: " << head << "(" << head->key << ", " << head->value << ")" << endl;
        }
        return;
    }

    int *getValueFromKey(string key) {
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
            if (debug) {
                cout << __FUNCTION__ << "->MostRecentKey: " << this->head->key << endl;
            }
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

    os << "DLL: Reverse" << endl;
    dll = cache.head;
    while (dll->next != nullptr) {
        dll = dll->next;
    }

    while (dll != nullptr) {
        os << dll->key << "-" << dll->value << endl;
        dll = dll->prev;
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

    cout << "-----------------------Test Case 1--------------------------------" << endl;
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

    cout << "-----------------------Test Case 2--------------------------------" << endl;
    cache = new LRUCache(1);

    key = "a";
    value = 1;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "a";
    value = 9001;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "b";
    value = 2;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "c";
    value = 3;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    delete cache;

    cout << "-----------------------Test Case 3--------------------------------" << endl;
    cache = new LRUCache(4);

    key = "a";
    value = 1;
    cout << "Inserting:" << key << " " << value << endl;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "b";
    value = 2;
    cout << "Inserting:" << key << " " << value << endl;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "c";
    value = 3;
    cout << "Inserting:" << key << " " << value << endl;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "d";
    value = 4;
    cout << "Inserting:" << key << " " << value << endl;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "a";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    key = "b";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    key = "c";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    key = "d";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    key = "e";
    value = 5;
    cout << "Inserting:" << key << " " << value << endl;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "e";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    key = "a";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }

    cout<<"Cache: " << *cache << endl;

    key = "b";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    key = "c";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    key = "d";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    delete cache;

    cout << "-----------------------Test Case 4--------------------------------" << endl;
    cache = new LRUCache(3);

    key = "b";
    value = 2;
    cout << "Inserting:" << key << " " << value << endl;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "a";
    value = 1;
    cout << "Inserting:" << key << " " << value << endl;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "c";
    value = 3;
    cout << "Inserting:" << key << " " << value << endl;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "a";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    key = cache->getMostRecentKey();
    cout << "Most Recently Key: " << key << endl;
    cout << endl;
    cout<<"Cache: " << *cache << endl;


    key = "a";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    /*

    key = cache->getMostRecentKey();
    cout << "Most Recently Key: " << key << endl;
    cout << endl;
    cout<<"Cache: " << *cache << endl;



    key = "d";
    value = 4;
    cout << "Inserting:" << key << " " << value << endl;
    cache->insertKeyValuePair(key, value);
    cout << *cache;


    key = "b";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;

    key = "a";
    value = 5;
    cout << "Inserting:" << key << " " << value << endl;
    cache->insertKeyValuePair(key, value);
    cout << *cache;

    key = "a";
    cout << "Get value for Key:" << key << endl;
    valPtr = cache->getValueFromKey(key);
    if (valPtr == nullptr) {
        cout << "Key Does not exist:"<< endl;
    } else {
        cout << "Value for Key:" << key << "-" << *valPtr << endl;
        cout << endl;
    }
    cout<<"Cache: " << *cache << endl;
*/
    delete cache;
}


#endif //GNU_LRUCACHE_H
