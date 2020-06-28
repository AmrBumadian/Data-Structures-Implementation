#include <iostream>
#include "OrderedList.h"

using namespace std;

template<class T>
OrderedList<T>::OrderedList() {
    head = last = nullptr;
    size = 0;
}

template<class T>
OrderedList<T>::OrderedList(int size, T value) {
    this->size = size;
    head = new Node<T>(value);
    last = head;

    int i = 1;
    while (i != size) {
        Node<T> *newNode = new Node<T>(value);
        last->next = newNode;
        last = last->next;
        ++i;
    }
}

template<class T>
void OrderedList<T>::copyList(const OrderedList<T> &other) {
    if (head != nullptr) { clear(); }
    if (other.head == nullptr) {
        return;
    }
    size = other.size;
    head = new Node<T>(other.head->value);
    last = head;
    Node<T> *current = other.head;

    int i = 1;
    while (i != size) {
        current = current->next;
        Node<T> *newNode = new Node<T>(current->value);
        last->next = newNode;
        last = last->next;
        ++i;
    }
}

template<class T>
OrderedList<T>::OrderedList(const OrderedList<T> &other) {
    head = last = nullptr;
    size = 0;
    copyList(other);
}

template<class T>
OrderedList<T>::~OrderedList() {
    Node<T> *current = head;

    while (size--) {
        head = head->next;
        delete current;
    }
}

template<class T>
OrderedList<T> &OrderedList<T>::operator=(const OrderedList<T> &other) {
    if (this != &other) { // avoid self-assignment
        copyList(other);
    }
    return *this;
}

template<class T>
void OrderedList<T>::insert(T value) {

    Node<T> *newNode = new Node<T>(value);
    if (head == nullptr) {
        head = last = newNode;
    } else if (value < head->value) {
        newNode->next = head;
        head = newNode;
    } else {
        if (value > last->value) {
            last->next = newNode;
            last = newNode;
        } else {
            Node<T> *current = head;
            while (current != nullptr && value <= current->value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    ++size;
}

template<class T>
void OrderedList<T>::remove(int position) {
    if (position >= size) {
        cerr << "Position Not Found";
    }
    Node<T> *garbage;
    if (position == 0) {
        garbage = head;
        head = head->next;
    } else {
        Node<T> *current = head;
        int i = 0;
        while (i != position - 1) {
            current = current->next;
            ++i;
        }
        garbage = current->next;
        current->next = current->next->next;
    }
    delete garbage;
    --size;
}

template<class T>
void OrderedList<T>::removeKey(T key) {
    int index = find(key);
    if (index != 1) {
        remove(index);
    }
}

template<class T>
int OrderedList<T>::find(T value) const {
    int counter = 0;
    Node<T> *current = head;
    while (current != nullptr && current->value < value) {
        ++counter;
        current = current->next;
    }
    if (current->value == value) {
        return counter;
    } else {
        return -1;
    }
}

template<class T>
void OrderedList<T>::clear() {
    Node<T> *current;

    while (head != nullptr) {
        current = head;
        head = head->next;
        delete current;
    }
    last = nullptr;
    size = 0;
}

template<class T>
int OrderedList<T>::length() const {
    return size;
}

template<class T>
T OrderedList<T>::front() const {

    assert(head != nullptr);
    return head->value;
}

template<class T>
T OrderedList<T>::back() const {

    assert(last != nullptr);
    return last->value;

}

template<class T>
void OrderedList<T>::print() const {
    Node<T> *current = head;

    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
