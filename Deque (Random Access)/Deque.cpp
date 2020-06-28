#include "Deque.h"
#include <bits/stdc++.h>

using namespace std;

template<class T>
Deque<T>::Deque() {
    size[0] = size[1] = size[2] = 0;
    capacity[0] = capacity[1] = capacity[2] = 1; // initialize each array capacity = 1;
    for (int i = 0; i < 3; ++i) { // allocate memory for each array
        array[i] = new T[1];
    }
}

template<class T>
Deque<T>::Deque(int size, T value) {
    this->size[1] = size; // set the size of the middle array to size
    this->size[0] = this->size[2] = 0; // set the other array sizes to 0
    array[0] = new T[1];
    array[1] = new T[size];
    array[2] = new T[1];
    for (int i = 0; i < size; ++i) { // add value to the middle array only
        array[1][i] = value;
    }
    capacity[1] = size;
    capacity[0] = capacity[2] = 1;
}

template<class T>
Deque<T>::Deque(const Deque<T> &other) {
    copyDeque(other);
}

template<class T>
Deque<T> &Deque<T>::operator=(const Deque<T> &other) {
    if (this != &other) { // avoid self-assignment
        deleteAll(); // if allocated before reset everything
        copyDeque(other); // copy the other deque to this
    }
    return *this;
}

template<class T>
Deque<T>::~Deque() {
    for (int i = 0; i < 3; ++i) {
        delete[] array[i];
    }
    delete array;
}

template<class T>
void Deque<T>::copyDeque(const Deque<T> &other) {
    for (int i = 0; i < 3; ++i) { // copying the capacities and the sizes
        capacity[i] = other.capacity[i];
        size[i] = other.size[i];
    }
    for (int i = 0; i < 3; ++i) { // allocating arrays at this
        array[i] = new T[capacity[i]];
    }
    for (int i = capacity[0] - 1; i >= capacity[0] - size[0]; --i) { // copying the front array from end to front
        array[0][i] = other.array[0][i];
    }
    for (int i = 0; i < size[1]; ++i) { // copying the middle array from begin to end
        array[1][i] = other.array[1][i];
    }
    for (int i = 0; i < size[2]; ++i) { // copying the back array from begin to end
        array[2][i] = other.array[2][i];
    }
}

template<class T>
void Deque<T>::deleteAll() {
    size[0] = size[1] = size[2] = 0;
    capacity[0] = capacity[1] = capacity[2] = 1;

    for (int i = 0; i < 3; ++i) {
        delete[] array[i];
    }
}

template<class T>
void Deque<T>::clear() {
    deleteAll();
    for (int i = 0; i < 3; ++i) { // reallocate capacities to 1
        array[i] = new T[1];
    }
}

template<class T>
void Deque<T>::pushFront(T value) { // elements pushed reversed end to front
    if (size[0] + 1 > capacity[0]) { // check if reallocation is needed
        capacity[0] *= 2; // double the capacity
        T *temp = array[0]; // pointer to the old array
        array[0] = new T[capacity[0]]; // reallocate new memory capacity

        int j = 1;
        for (int i = capacity[0] - 1;
             i >= capacity[0] - size[0]; --i) { // copy the elements to the new array in reversed order
            array[0][i] = temp[size[0] - j];
            ++j;
        }
        array[0][capacity[0] - size[0] - 1] = value; // add element at the current unfilled position
        delete[] temp; // free the old memory

    } else {
        array[0][capacity[0] - size[0] - 1] = value;
    }
    ++size[0];
}

template<class T>
void Deque<T>::popFront() {

    if (size[0] - 1 <= (capacity[0] / 2)) { // check if reallocation is needed
        capacity[0] = ((capacity[0] / 2) > 0) ? (capacity[0] / 2) : 1; // insure that capacity is at least 1
        T *temp = array[0]; // pointer to the old array
        array[0] = new T[capacity[0]]; // reallocate new memory capacity

        for (int i = 0; i < size[0] - 1; ++i) {
            array[0][i] = temp[i];
        }
        delete[] temp; // free the old memory
    }
    --size[0];
}

template<class T>
void Deque<T>::pushBack(T value) {
    if (size[2] + 1 > capacity[2]) { // check if reallocation is needed
        capacity[2] *= 2; // double the capacity
        T *temp = array[2]; // pointer to the old array
        array[2] = new T[capacity[2]]; // reallocate new memory capacity

        for (int i = 0; i < size[2]; ++i) { // copy the elements to the new array
            array[2][i] = temp[i];
        }
        array[2][size[2]] = value;
        delete[] temp; // free the old memory

    } else {
        array[2][size[2]] = value;
    }
    ++size[2];
}

template<class T>
void Deque<T>::popBack() {
    if (size[2] - 1 <= (capacity[2] / 2)) { // check if reallocation is needed
        capacity[2] = ((capacity[2] / 2) > 0) ? (capacity[2] / 2) : 1; // insure that capacity is at least 1
        T *temp = array[2]; // pointer to the old array
        array[2] = new T[capacity[2]]; // reallocate new memory capacity

        for (int i = 0; i < size[2] - 1; ++i) {
            array[2][i] = temp[i];
        }
        delete[] temp; // free the old memory
    }
    --size[2];
}

template<class T>
int Deque<T>::length() const {
    return (size[0] + size[1] + size[2]);
}

template<class T>
T Deque<T>::front() const {
    return (*this)[0]; // return first element using the [] operator
}

template<class T>
T Deque<T>::back() const {
    return (*this)[length() - 1]; // return last element using the [] operator
}

template<class T>
void Deque<T>::print() const {
    ostream_iterator<T> screen(cout, " "); // iterator to copy the content of arrays to the ostream object cout

    reverse_copy(array[0] + (capacity[0] - size[0]), array[0] + capacity[0], screen); // reverse copy the front array

    copy(array[1], array[1] + size[1], screen); // copying middle array

    copy(array[2], array[2] + size[2], screen); // copying back array

    cout << endl;
}

template<class T>
T Deque<T>::operator[](int index) const {
    if (index + 1 <= size[0]) { // if exists in the front array
        return array[0][capacity[0] - index - 1];
    } else if (index + 1 <= size[0] + size[1]) { // if exists in the middle array
        return array[1][index - size[0]];
    } else if (index + 1 <= size[0] + size[1] + size[2]) { // if exists in the last array
        return array[2][index - size[0] - size[1]];
    } else { // out of bound (garbage is returned)
        cerr << "index out of bounds\n";
    }
}
