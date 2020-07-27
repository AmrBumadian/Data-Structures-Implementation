#include "Queue.h"
#include <assert.h>
#include <iostream>

using namespace std;

template<class T>
void Queue<T>::copy(const Queue<T> &other) {
    length = other.length;
    head = new Node<T>(other.head->value); // deep copy for head;
    tail = head;

    Node<T> *current = other.head->next; // pointer to the next node in other to be copied

    while (current != nullptr) {
        Node<T> *newNode = new Node<T>(current->value);
        tail->next = newNode; // point the tail next to the new node
        tail = newNode; // make the new node the tail
        current = current->next; // get next element ot be copied
    }
}

template<class T>
Queue<T>::Queue() : length(0), head(nullptr), tail(nullptr) {}

template<class T>
Queue<T>::Queue(const Queue<T> &other) {
    if (other.head != nullptr) { copy(other); } // avoid method call for empty Queue
    else {
        head = tail = nullptr;
    }
}

template<class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other) {
    
    if (this != &other && other.head != nullptr) { // avoid self-assignemnt and method call for empty Queue
		clear(); // de-allocate
        copy(other);
    }
    return *this; // return this object by reference
}

template<class T>
Queue<T>::~Queue() {
    Node<T> *garbage;
    while (head != nullptr) {
        Node<T> *garbage = head;
        head = head->next;
        delete garbage;
    }
}

template<class T>
void Queue<T>::push(T value) {
    Node<T> *newNode = new Node<T>(value);
    if (length == 0) {
        head = tail = newNode;
    } else {
        tail->next = newNode; // point the tail next to the new node
        tail = newNode; // make the new node the tail
    }
    ++length;
}

template<class T>
T Queue<T>::pop() {
    if (length != 0) {
        T value = head->value; // value to be returned
        Node<T> *garbage = head; // point to the front element
        head = head->next; // make the next element the front
        delete garbage; // delete the node
        --length;
        return value;
    } else {
        cerr << "\ncannot delete from empty Queue\n";
    }
}

template<class T>
T Queue<T>::front() {
    assert(length != 0);
    return head->value;
}

template<class T>
T Queue<T>::back() {
    assert(length != 0);
    return tail->value;
}

template<class T>
int Queue<T>::size() {
    return length;
}

template<class T>
bool Queue<T>::empty() {
    return (length == 0);
}

template<class T>
void Queue<T>::clear() { // reset all
    Node<T> *garbage;
    while (head != nullptr) {
        Node<T> *garbage = head;
        head = head->next;
        delete garbage;
    }
    tail = nullptr;
    length = 0;
}

