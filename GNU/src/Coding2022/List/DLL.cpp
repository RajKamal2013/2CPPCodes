//
// Created by Raj Kamal on 27/08/22.
//

#include "DLL.h"

void testDLL(){
    DLL *list = new DLL();
    for (int i = 0; i < 10; i++) {
        list->append(i);
    }
    for (int i = 9; i >=0; i-- ) {
        list->insert(i);
    }

    cout << list;
    list->reverse();
    cout << list;
    list->reverse();
    cout << list;

    int data = 10;
    bool ret = list->find(data);
    cout << data << " Exist: " << ret << endl;

    list->pop();
    cout << list;

    list->dequeue();
    cout << list;

    data = 8;
    list->remove(data);
    cout << list;

}