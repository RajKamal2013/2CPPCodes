//
// Created by Raj Kamal on 8/30/18.
//

#ifndef CPP_CODES_THREADSAFE_STACK_H
#define CPP_CODES_THREADSAFE_STACK_H


#include <exception>
#include <stack>
#include <mutex>


struct empty_stack : std::exception {
    const char *what() const throw();

};

template<typename  T>
class threadSafe_Stack {

private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    threadSafe_Stack() {}

    threadSafe_Stack(const threadSafe_Stack &other) {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }

    threadSafe_Stack &operator=(const threadSafe_Stack &) = delete;

    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(std::make_shared<T>(std::move(data.top())));
        data.pop();
        return res;
    }

    void pop(T &value) {
        std::lock_guard<std::mutex> lock(m);
        //if (data.empty()) throw empty_stack();
        if (data.empty()) { return; };
        value = std::move(data.top());
        data.pop();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    };

};


#endif //CPP_CODES_THREADSAFE_STACK_H
