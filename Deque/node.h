//
// Created by Amr Bumadian on 6/3/2020.
//

#ifndef DEQUE_NODE_H
#define DEQUE_NODE_H

template<class T>
class node {
private:
    T value;
    node<T> *next;
    node<T> *previous;
public:
    node() {
        T *next = nullptr;
        T *previous = nullptr;
    }

    T getValue() const {
        return value;
    }

    void setValue(T value) {
        node::value = value;
    }

    node<T> *getNext() const {
        return next;
    }

    void setNext(node<T> *next) {
        node::next = next;
    }

    node<T> *getPrevious() const {
        return previous;
    }

    void setPrevious(node<T> *previous) {
        node::previous = previous;
    }
};

#endif //DEQUE_NODE_H
