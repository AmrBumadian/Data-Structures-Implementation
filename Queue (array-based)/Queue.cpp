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
    delete[] array;
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
        b = (b + 1) % capacity; // if b + 1 = capacity, go to the empty space in the front b = 0
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
        f = (f + 1) %
            capacity; //  discard this element and point to the next, if the next index == capacity point to the front of the array
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

template<class T>
bool Queue<T>::resize(int size) { // resize to bigger size only so elements won't be lost
    if (size < capacity) {
        cerr << "\ncannot make the Queue smaller\n";
        return false; // cannot resize
    }
    T *temp = new T[size]; // allocate new capacity
    int i = 0, j = f; // pointers to copy the elements i for the new and j for the old
    while (j != b) {
        temp[i] = array[j];
        ++i;
        j = (j + 1) % capacity; // make the pointer cycle through the array till it reach b
    }
    temp[i] = array[b]; // copy the element at b
    delete[] array; // delete the old array
    array = temp; // point the array pointer to the new array
    capacity = size;
    f = 0; // front is now the first index
    b = length - 1; // back is the last occupied index
    return true; // successfully resized;
}



