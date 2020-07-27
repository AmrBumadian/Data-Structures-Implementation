#include "AList.h"
#include <bits/stdc++.h>

using namespace std;

// constructors

template<class T>
AList<T>::AList() : size(1), length(0), list(new T[1]) {}

template<class T>
AList<T>::AList(int size) : size(size), length(0), list(new T[size]) {}

template<class T>
AList<T>::AList(int size, T value) : size(size), length(size), list(new T[size]) {
    for (int i = 0; i < size; ++i) {
        list[i] = value;
    }
}

template<class T>
AList<T>::AList(const AList<T> &other) { // copy constructor
    size = other.size;
    length = other.length;
    list = new T[size];
    assert(list != nullptr); // insure that memory is allocated

    for (int i = 0; i < length; ++i) {
        list[i] = other.list[i];
    }
}

///////////////////////////////////////////////////////////////

//Assignment operator

template<class T>
const AList<T>& AList<T>::operator=(const AList<T> &other) {

    if (this != &other) { // avoid self assignment
		delete [] list;
        size = other.size;
        length = other.length;
        list = new T[size];
        assert(list != nullptr); // insure that memory is allocated

        for (int i = 0; i < length; ++i) {
            list[i] = other.list[i];
        }
    }
    return *this;
}

///////////////////////////////////////////////////////////////
template<class T>
void AList<T>::insert(T value) { // insert value at the end
    if (length == size) {
        cerr << "List is full" << endl;
    } else {
        list[length++] = value;
    }
}

template<class T>
void AList<T>::insertAt(int index, T value) { // insert at specific index
    if (index >= 0 && index < size) { // check that index is in range
        list[index] = value;
        ++length;
    } else { // if not in range
        throw new out_of_range("IndexOutOfBound");
    }
}


template<class T>
void AList<T>::remove(int index) { // remove element at specific index
    if (index >= 0 && index < size) {
        list[index] = 0;
        --length;
    } else { // if not in range
        throw new out_of_range("IndexOutOfBound");
    }
}

template<class T>
int AList<T>::indexOf(T val) { // find the index of element
    for (int i = 0; i < size; ++i) {
        if (list[i] == val) { // found
            return i;
        }
    }
    return -1; // not found
}

template<class T>
T AList<T>::elementAt(int index) { // get value at index
    if (index >= 0 && index < size) { // check index in range
        return list[index];
    } else { // index out of range
        throw new out_of_range("IndexOutOfBound");
    }
}

template<class T>
bool AList<T>::retrieveAt(int index, T &container) { // put the element at index in container
    if (index >= 0 && index < size) {
        container = list[index];
        return true; // if exists
    } else {
        return false; // doesn't exist
    }
}

template<class T>
void AList<T>::clear() { // reset the list values
    for (int i = 0; i < size; ++i) {
        list[i] = 0;
    }
    length = 0;
}

//////////////////////////////////////////////////////////////

template<class T>
int AList<T>::getSize() const { // max capacity
    return size;
}

template<class T>
int AList<T>::getLength() const { // filled space
    return length;
}

template<class T>
bool AList<T>::isEmpty() const {
    return (length == 0);
}

template<class T>
bool AList<T>::isFull() const {
    return (length == size);
}

template<class T>
void AList<T>::print() const {
    for (int i = 0; i < length; ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
}

template<class T>
AList<T>::~AList() {
    delete[] list;
}