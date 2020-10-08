//
// Created by Raj Kamal on 8/11/18.
//

#include <iostream>
#include <thread>
#include "Threads/helloWorld.h"


void helloWorld::hello()
{
    std::cout << "Hello Concurrent World" << std::endl;
}

void helloWorld::runThread()
{
    std::thread t(&helloWorld::hello, this);
    t.join();
}

void printhello()
{
    std::cout<<"HI This is hello for concurrent world !!" << std::endl;
}
int main()
{
    helloWorld hi;
    hi.runThread();
    std::thread t1(printhello);
    t1.join();
    return 0;
}

