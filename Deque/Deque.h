//
// Created by Amr Bumadian on 6/3/2020.
//

#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H

#include "node.h"

template<class T>
class Deque {
private:
    node<T> *front;
    node<T> *back;
    int size;

public:
    Deque() {
        front = back = nullptr;
        size = 0;
    }

    Deque(int size) {
        Deque(size, 0);
    }

    Deque(int size, T value) {
        this->size = size;
        for (int i = 0; i < size; ++i) {
            push(value);
        }
    }

    void push(T value) {
        node<T> *newNode;
        if (size == 0) {
            newNode = new node<T>;
            newNode->setValue(value);
            front = back = newNode;
        } else {
            newNode = new node<T>;
            newNode->setValue(value);
            newNode->setPrevious(back);
            back->setNext(newNode);
            back = newNode;
        }
        ++size;
    }

    void pop() {

        node<T> *tempNode = back;
        back = back->getPrevious();
        if (back != nullptr) { back->setNext(nullptr); }
        delete tempNode;
        --size;
        if (size == 0) {
            front = back = nullptr;
        }
    }

    void inject(T value) {
        node<T> *newNode;
        if (size == 0) {
            newNode = new node<T>;
            newNode->setValue(value);
            front = back = newNode;
        } else {
            newNode = new node<T>;
            newNode->setValue(value);
            newNode->setNext(front);
            front->setPrevious(newNode);
            front = newNode;
        }
        ++size;
    }

    void eject() {
        node<T> *tempNode = front;
        front = front->getNext();
        if (front != nullptr) { front->setPrevious(nullptr); }
        delete tempNode;
        --size;
        if (size == 0) {
            front = back = nullptr;
        }
    }

    T getFront() const {
        return front->getValue();
    }

    T getBack() const {
        return back->getValue();
    }

    int getSize() const {
        return size;
    }

    ~Deque() {
        node<T> *tempNode = front;
        for (int i = 0; i < size; ++i) {
            front = front->getNext();
            delete tempNode;
            tempNode = front;
            --size;
        }
    }
};


#endif //DEQUE_DEQUE_H
