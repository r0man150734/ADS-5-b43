// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <stdexcept>
#include <array>

template<typename T, int size>
class TStack {
 private:
    std::array<T, size> data;
    int topIndex;

 public:
    TStack() : topIndex(-1) {}

    void push(const T& value) {
        if (isFull()) {
            throw std::runtime_error("Stack overflow");
        }
        data[++topIndex] = value;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack underflow");
        }
        return data[topIndex--];
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


