#include <assert.h>
#include "Stack.h"

using namespace std;

template<class T>
void Stack<T>::copyStack(const Stack<T> &other) {
    capacity = other.capacity;
    length = other.length;
    array = new T[capacity];

    for (int i = 0; i < length; ++i) {
        array[i] = other.array[i];
    }
}

template<class T>
Stack<T>::Stack() : capacity(1), length(0) {
    array = new T[capacity];
}

template<class T>
Stack<T>::Stack(const Stack<T> &other) {
    copyStack(other);
}

template<class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other) {
    if (this != &other) {
		delete [] array;
        copyStack(other);
    }
    return *this;
}

template<class T>
Stack<T>::~Stack() {
    delete[] array;
}


template<class T>
void Stack<T>::push(T value) {
    if (length + 1 > capacity) { // check if reallocation is needed
        capacity *= 2; // double the capacity
        T *temp = array; // pointer to the old array
        array = new T[capacity]; // reallocate new memory capacity

        for (int i = 0; i < length; ++i) { // copy the elements to the new array
            array[i] = temp[i];
        }
        array[length] = value;
        delete[] temp; // free the old memory

    } else {
        array[length] = value;
    }
    ++length;
}

template<class T>
T Stack<T>::pop() {
    assert(length!=0);
    T value = array[length - 1];
    if (length - 1 <= (capacity / 2)) { // check if reallocation is needed
        capacity = ((capacity / 2) > 0) ? (capacity / 2) : 1; // insure that capacity is at least 1
        T *temp = array; // pointer to the old array
        array = new T[capacity]; // reallocate new memory capacity

        for (int i = 0; i < length - 1; ++i) {
            array[i] = temp[i];
        }
        delete[] temp; // free the old memory
    }
    --length;
    return value;
}

template<class T>
T Stack<T>::top() const {
    assert(length!=0);
    return array[length - 1];
}


template<class T>
bool Stack<T>::empty() const {
    return (length == 0);
}

template<class T>
bool Stack<T>::size() const {
    return length;
}

template<class T>
void Stack<T>::clear() {
    delete[] array;
    capacity = 1;
    length = 0;
    array = new T[capacity];
}
