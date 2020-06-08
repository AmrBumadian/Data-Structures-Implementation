#include <bits/stdc++.h>
#include "List.h"
#include "Node.h"

using namespace std;

template<typename T>
List<T>::List() : size(0), head(nullptr), tail(nullptr) {
    dummy = new node<T>;
}

template<typename T>
List<T>::List(T value, int sz) : size(0) {
    dummy = new node<T>;
    for (int i = 0; i < sz; ++i) {
        pushBack(value);
    }
}

template<typename T>
List<T>::List(const List<T> &source) : size(0) {
    dummy = new node<T>;
    list_iterator it(source.head);
    while (size != source.size) {
        T value = it.p->getVal();
        pushBack(value);
        ++it;
    }
}

template<typename T>
void List<T>::pushBack(T value) {
    node<T> *data = new node<T>(value);
    if (size == 0) {
        head = tail = data;
        data->setNxt(dummy);
        ++size;
        return;
    }
    data->setNxt(dummy);
    dummy->setPrv(data);
    tail->setNxt(data);
    data->setPrv(tail);
    tail = data;
    ++size;
}

template<typename T>
void List<T>::insert(T value, list_iterator it) {
    node<T> *data = new node<T>(value);
    if (size == 0 || it == dummy) {
        pushBack(value);
        return;
    }
    if (it == head) {
        data->setNxt(head);
        head = data;
    } else if (it == tail) {
        data->setNxt(tail);
        data->setPrv(tail->getPrv());
        tail->setPrv(data);
    } else {
        data->setNxt(it.p);
        data->setPrv(it.p->getPrv());
        data->getPrv()->setNxt(data);
        it.p->setPrv(data);
    }
    ++size;
}

template<typename T>
typename List<T>::list_iterator List<T>::erase(list_iterator it) {
    list_iterator next;
    if (size == 0) throw exception();
    else if (size == 1) {
        next = nullptr;
        head = tail = nullptr;
        delete it.p;
    }
    else {
        if (it.p == dummy) {
            it = dummy->getPrv();
        }
        if (it.p == head) {
            head = head->getNxt();
            next = head;
            delete it.p;
        } else if (it.p == tail) {
            tail = tail->getPrv();
            next = tail;
            delete it.p;
        } else {
            next = it.p->getNxt();
            it.p->getPrv()->setNxt(it.p->getNxt());
            it.p->getNxt()->setPrv(it.p->getPrv());
            delete it.p;
        }
    }
    --size;
    return next;
}

template<typename T>
void List<T>::printAll() {

    list_iterator it(head);
    while (it.p != dummy) {
        cout << (it.p->getVal()) << " ";
        ++it;
    }
    cout << "\n";
}

template<typename T>
List<T> &List<T>::operator=(const List<T> &source) {
    list_iterator current(head);
    while (current.p != dummy) {
        node<T> *garbage = current.p;
        current.p = current.p->getNxt();
        delete garbage;
    }
    size = 0;
    list_iterator it(source.head);
    while (size != source.size) {
        pushBack(it.p->getVal());
        ++it;
    }
    return *this;
}

template<typename T>
inline int List<T>::getSize() {
    return size;
}

template<typename T>
List<T>::~List() {
    list_iterator current(head);
    while (size--) {
        node<T> *garbage = current.p;
        current.p = current.p->getNxt();
        delete garbage;
    }
    delete dummy;
}