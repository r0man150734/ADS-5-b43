// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <stdexcept>  

template<typename T, int size>
class TStack {
private:
    T data[size];      
    int topIndex;      

public:
    TStack() : topIndex(-1) {}  


    void push(const T& value) {
        if (isFull()) {
            throw std::runtime_error("Stack overflow");
        }
        data[++topIndex] = value;
    }


    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack underflow");
        }
        --topIndex;
    }


    T& top() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return data[topIndex];
    }

    const T& top() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return data[topIndex];
    }


    bool isEmpty() const {
        return topIndex == -1;
    }


    bool isFull() const {
        return topIndex == size - 1;
    }


    int count() const {
        return topIndex + 1;
    }


    void clear() {
        topIndex = -1;
    }
};

#endif  // INCLUDE_TSTACK_H_

