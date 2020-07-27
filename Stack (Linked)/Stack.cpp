#include <bits/stdc++.h>
#include "Stack.h"

using namespace std;

template<class T>
void Stack<T>::copy(const Stack<T> &other) {
    if (other.head == nullptr) {
        head = nullptr;
        length = 0;
        return;
    }
    length = other.length;
    head = new Node<T>(other.head->value);
    Node<T> *newNode, *last = head;
    Node<T> *current = other.head->next;
    for (int i = 1; i < length; ++i) {
        newNode = new Node<T>(current->value);
        last->next = newNode;
        last = newNode;
        current = current->next;
    }
}

template<class T>
Stack<T>::Stack() : length(0) {
    head = nullptr;
}

template<class T>
Stack<T>::Stack(const Stack<T> &other) {
    copy(other);
}

template<class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other) {

    if (this != &other && other.head != nullptr) {
		clear();
        copy(other);
    }
    return *this;
}

template<class T>
Stack<T>::~Stack() {
    Node<T> *current;

    while (head != nullptr) {
        current = head;
        head = head->next;
        delete current;
    }
}


template<class T>
void Stack<T>::push(T value) {
    Node<T> *newNode = new Node<T>(value);
    if (length == 0) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    ++length;
}

template<class T>
T Stack<T>::pop() {
    assert(head != nullptr);
    T value = head->value;
    if (length == 0) {
        delete head;
        head = nullptr;
    } else {
        Node<T> *garbage = head;
        head = head->next;
        delete garbage;
    }
    --length;
    return value;
}

template<class T>
T Stack<T>::top() {
    assert(head != nullptr);
    return head->value;
}

template<class T>
void Stack<T>::clear() {
    Node<T> *current;

    while (head != nullptr) {
        current = head;
        head = head->next;
        delete current;
    }
    length = 0;
}

template<class T>
int Stack<T>::size() {
    return length;
}

template<class T>
bool Stack<T>::empty() {
    return (length == 0);
}