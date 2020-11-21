//
// Created by Amr Bumadian on 6/27/2020.
//

#include "Vector.h"
#include <bits/stdc++.h>

using namespace std;

template<class T>
Vector<T>::Vector() : size(0), capacity(1) {
    array = new T[capacity];
}

template<class T>
Vector<T>::Vector(int capacity) : size(capacity), capacity(capacity) {
    array = new T[capacity];
}

template<class T>
Vector<T>::Vector(int size, T value) : size(size), capacity(size) {
    array = new T[capacity];
    for (int i = 0; i < size; ++i) {
        array[i] = value;
    }
}

template<class T>
Vector<T>::Vector(const Vector<T> &other) {
    size = other.size;
    capacity = other.capacity;
    array = new T[capacity];

    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
    size = other.size;
    capacity = other.capacity;
    array = new T[capacity];

    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }

    return *this;
}

template<class T>
Vector<T>::~Vector() {
    delete[] array;
}

template<class T>
void Vector<T>::pushBack(T value) {
    if (size + 1 > capacity) { // check if reallocation is needed
        capacity *= 2; // double the capacity
        T *temp = array; // pointer to the old array
        array = new T[capacity]; // reallocate new memory capacity

        for (int i = 0; i < size; ++i) { // copy the elements to the new array
            array[i] = temp[i];
        }
        array[size] = value;
        delete[] temp; // free the old memory

    } else {
        array[size] = value;
    }
    ++size;
}

template<class T>
void Vector<T>::popBack() {
    if (size - 1 <= (capacity / 4)) { // check if reallocation is needed
        capacity = ((capacity / 2) > 0) ? (capacity / 2) : 1; // insure that capacity is at least 1
        T *temp = array; // pointer to the old array
        array = new T[capacity]; // reallocate new memory capacity

        for (int i = 0; i < size - 1; ++i) {
            array[i] = temp[i];
        }
        delete[] temp; // free the old memory
    }
    --size;
}

template<class T>
void Vector<T>::insert(int index, T value) {
    if (index < 0 || index > size) {
        throw new out_of_range("index out of bounds");
    }
    if (index == size) { // adding at the last position
        pushBack(value);
        return;
    } else {
        if (size + 1 > capacity) { // check if reallocation is needed
            capacity *= 2;
            T *temp = array; // pointer to the old array
            array = new T[capacity]; // reallocating new memory

            int j=0;
            for (int i=0;i<size;++i) { // copy the elements and shift them around index
                if (i==index) {
                    ++j;
                }
                array[j] = temp[i];
                ++j;
            }

            array[index] = value;
            delete[] temp; // free old memory
        } else {
            for (int i = size; i > index; --i) { // shift the elements after index to the right
                array[i] = array[i - 1];
            }
            array[index] = value;
        }
    }
    ++size;
}

template<class T>
void Vector<T>::resize(int newSize) {
    if (newSize == 0) {
        clear();
        return;
    }
    if (newSize == capacity) { return; } // no reallocation is needed
    else {
        capacity = newSize;
        T *temp = array;
        array = new T[capacity];

        for (int i = 0; i < size; ++i) {
            array[i] = temp[i];
        }
    }
    size = newSize;
}

template<class T>
void Vector<T>::erase(int index) {
    if (index == size - 1) {
        popBack();
        return;
    }
    if (index < 0 || index >= size) {
        throw new out_of_range("index out of bounds");
    }

    if (size - 1 <= (capacity / 4)) {
        capacity = ((capacity / 2) > 0) ? (capacity / 2) : 1;
        T *temp = array;
        array = new T[capacity];

        int j = 0;
        for (int i = 0; i < size - 1;) {
            if (j != index) {
                array[i] = temp[j];
                ++i;
            }
            ++j;
        }
    } else {
        for (int i = index; i < size - 1; ++i) { // shift elements after index to the left
            array[i] = array[i + 1];
        }
    }
    --size;
}

template<class T>
void Vector<T>::clear() { // reset
    delete[] array;
    size = 0;
    capacity = 1;
    array = new T[capacity];
}

template<class T>
T &Vector<T>::at(int index) {
    if (index >= 0 && index < capacity) {
        return array[index];
    }
    throw new out_of_range("index out of bounds");
}

template<class T>
T &Vector<T>::operator[](int index) {
    return array[index];
}

template<class T>
bool Vector<T>::empty() {
    return (size == 0);
}

template<class T>
int Vector<T>::Size() {
    return size;
}

template<class T>
int Vector<T>::Capacity() {
    return capacity;
}

template<class T>
void Vector<T>::print() {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}