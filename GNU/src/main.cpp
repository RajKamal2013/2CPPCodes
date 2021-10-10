//
// Created by Raj Kamal on 10/8/20.
//

#include <iostream>
#include <cstring>
#include <vector>

#include <chrono>

#include "Codes/helloworld.h"
#include "Codes/Util/IntegerFileGenerator.h"
#include "Codes/Sorting/qsort.h"
#include "Codes/DS/AList.h"
#include "Codes/DS/DList.h"
#include "Codes/DS/SList.h"
#include "Codes/DS/AStack.h"
#include "Codes/DS/LStack.h"
#include "Coding/ThreeSum.h"
#include "Coding/twoSum.h"
#include "Coding/validateSubsequence.h"
#include "Coding/SortedSquare.h"
#include "Coding/SmallestDifference.h"
#include "Coding/MoveElementsToEnd.h"


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
void SortingTest()
{
    /* Start Coding */
    std::cout << "1. ******Lets start coding *******" << std::endl;
    helloworld *test = new helloworld();
    test->start_coding();
    std::cout << std::endl;

    /* File Generation Test */
    std::cout << "2. *******Lets test file generation and random number generation ********" << std::endl;
    IntegerFileGenerator *fio = new IntegerFileGenerator(50, 500, "SampleInput.txt", "SampleOutput.txt");
    fio->generate();
    std::vector<int> vec;
    vec = fio->read();
    std::cout << "size of vector:" << vec.size() << std::endl;
    for (int data:vec) {
        std::cout << data << " " ;
    }
    std::cout <<std::endl;
    fio->write(vec);

    std::cout <<std::endl;

    /*Qsort Testing */
    std::cout << "3. ****** Lets Test Qsort " << std::endl;
    IntegerFileGenerator *qsortIo = new IntegerFileGenerator(100, 700, "QsortInput.txt", "QsortOutput.txt");
    qsortIo->generate();
    std::vector<int> qvec;
    qvec = qsortIo->read();
    for (int data:qvec) {
        std::cout << data << " ";
    }
    std::cout << std::endl;
    QSort *qfio = new QSort(std::move(qvec), qvec.size());
    auto start = std::chrono::steady_clock::now();
    qvec = qfio->run();
    auto end = std::chrono::steady_clock::now();
    std::cout << "Elapsed time in nanoseconds "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()
              << " ns"
              <<std::endl;
     qsortIo->write(qvec);
    for (int data:qvec) {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    std::cout <<std::endl;
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
int main() {
    std::cout << "Testing main " << std::endl;
    test_moveElementsToEnd();
}