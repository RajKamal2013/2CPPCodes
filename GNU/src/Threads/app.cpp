
// Created by Raj Kamal on 9/1/18.

#include "Threads/threadSafe_Stack.h"
#include<iostream>
#include<thread>
#include <condition_variable>

#define THREAD_COUNT 5
#define MAX 100

threadSafe_Stack<int> s;
std::mutex mtx[THREAD_COUNT];
std::condition_variable cv[THREAD_COUNT];
int available[THREAD_COUNT];
int data[3*THREAD_COUNT];


int add_data(int id)
{
    int i = id;
    while(1) {
        std::unique_lock<std::mutex>lock(mtx[id]);
        cv[id].wait(lock, [&id] {return (available[id] == 1);});
        s.push(data[id]);
        data[i] = -1;
        available[id] = 0;
        i = (i + THREAD_COUNT) % (3 *THREAD_COUNT);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main()
{
    int input[MAX];
    int idx = 0;
    std::thread t[THREAD_COUNT];
    int tid = 0;
    int tsig = 0;
    for (int i = 0; i < THREAD_COUNT; i++) {
        t[i] = std::thread(add_data, i);
    }
    while (!std::cin.eof())
    {
        std::cin >> input[idx];
        data[tid] = input[idx];
        available[tsig] = true;
        cv[tsig].notify_one();
        tid = (tid + 1) % (3 * THREAD_COUNT);
        idx = (idx + 1) % MAX;
        tsig = (tsig + 1) % THREAD_COUNT;
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        t[i].join();
    }

    int elem = 0;

    std::cout <<"Poping data from Stack" << std::endl;
    while (!s.empty())
    {
        s.pop(elem);
        std::cout << elem << std::endl;
    }

    return 0;
}

