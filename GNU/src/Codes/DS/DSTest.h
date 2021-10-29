//
// Created by kamr on 10/28/2021.
//

#ifndef GNU_DSTEST_H
#define GNU_DSTEST_H


void AListTest()
{
    AList<int> arr(10);
    int k = 0;
    for (int i = 10; i < 30; i++) {
        arr.append(i);
        k = k + 1;
    }

    for (auto itr = arr.begin(); itr != arr.end(); itr++) {
        std::cout << *itr << "  ";
    }
    std::cout << std::endl;

    bool ret = arr.find(15);
    std::cout << " 15 is present:" << ret << std::endl;

    ret = arr.find(100);
    std::cout << "100 is present :" << ret << std::endl;

    std::cout << "at index 2 :" << arr[2] << std::endl;

    arr.remove(18);

    for (auto itr = arr.begin(); itr != arr.end(); itr++) {
        if (*itr != INT32_MAX)
            std::cout << *itr << "  ";
    }
}


void SListTest() {
    SList<int> sll;

    std::cout << "inside SlistTest" << "\n";

    for (int i = 0; i < 50; i++) {
        sll.append(i);
    }

    std::cout << "size :" <<sll.length() << std::endl;
    int currpos = sll.currPos();

    sll.moveToStart();

    std::cout << "< ";
    int i;
    for (sll.moveToStart(); sll.currPos() < sll.length(); sll.next()) {
        std::cout << sll.getValue() << " ";
    }
    std::cout << ">\n";
    sll.moveToPos(currpos); // Reset the fence to its original position
}

/* Double linked list test */
void DListTest()
{
    DList<int> dll;

    for (int i = 0; i < 30; i++) {
        dll.append(i);
    }

    std::cout << "Data in the list " << std::endl;

    for (auto obj:dll) {
        std::cout <<obj << " ";
    }
    std::cout << std::endl;

    int num1 = 10;
    std::cout << "Num " << num1 << " is present:" << dll.find(num1) <<std::endl;

    int num2 = 100;
    std::cout << "Num " << num2 << " is present:" << dll.find(num2) <<std::endl;
    /*
    for (auto itr = dll.begin(); itr != dll.end(); itr++) {
        std::cout << *itr << std::endl;
    }
     */
}



void AStackTest() {
    AStack<int> stk(20);
    for (int i = 0; i < 10; i++) {
        stk.push(i);
    }

    std::cout << "size of stack:" << stk.size() << "\n";
    int data;
    while (!stk.empty()) {
        data = stk.pop();
        std::cout << data << " ";
    }
    std::cout << std::endl;
}

void LStackTest() {
    LStack<int> stk;
    for (int i = 0; i < 10; i++) {
        stk.push(i);
    }

    std::cout << "size of stack:" << stk.size() << "\n";
    int data;
    while (!stk.empty()) {
        data = stk.pop();
        std::cout << data << " ";
    }
    std::cout << std::endl;
}
#endif //GNU_DSTEST_H
