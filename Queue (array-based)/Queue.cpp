#include <assert.h>
#include <iostream>
#include "Queue.h"
using namespace std;

template<class T>
void Queue<T>::copy(const Queue<T> &other) {
    f = other.f;
    b = other.b;
    length = other.length;
    capacity = other.capacity;

    array = new T[capacity];

    for (int i = 0; i < capacity; ++i) {
        array[i] = other.array[i];
    }
}

template<class T>
Queue<T>::Queue(int size) : length(0), capacity(size) {
    f = 0;
    b = capacity - 1;
    array = new T[capacity];
}

template<class T>
Queue<T>::Queue(const Queue<T> &other) {
    copy(other);
}

template<class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other) {
    if (this != &other) {
        copy(other);
    }
    return *this;
}

template<class T>
Queue<T>::~Queue() {
    delete[] array;
}

template<class T>
void Queue<T>::push(T value) {
    if (length != capacity) {
        b = (b + 1) % capacity;
        array[b] = value;
    } else {
        cerr << "\nQueue is full" << endl;
        return;
    }
    ++length;
}

template<class T>
T Queue<T>::pop() {
    if (length == 0) {
        cerr << "\nCannot remove from empty Queue" << endl;
    } else {
        T value = array[f];
        f = (f + 1) % capacity;
        --length;
        return value;
    }
}

template<class T>
T Queue<T>::front() {
    assert(length != 0);
    return array[f];
}

template<class T>
T Queue<T>::back() {
    assert(length != 0);
    return array[b];
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
void Queue<T>::clear() {
    delete[] array;
    capacity = 1;
    length = 0;
    array = new T[capacity];
}
