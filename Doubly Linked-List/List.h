#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
#ifndef S1P1_LIST_H
#define S1P1_LIST_H

template<typename T>
class List {
    node<T> *head;
    node<T> *tail;
    node<T> *dummy;
    int size;
public:
    List();

    List(T value, int sz) ;

    List(const List<T> &source);

    class list_iterator {
        friend class List;
        node<T> *p;
    public:
        list_iterator() : p(nullptr) {}

        list_iterator(node<T> *pointer) : p(pointer) {}

        list_iterator operator++() {
            if (p->getNxt()==nullptr) throw exception();
            p = p->getNxt();
            return *this;
        }

        list_iterator operator++(int) {
            list_iterator i = p;
            if (p->getNxt()==nullptr) throw exception();
            p = p->getNxt();
            return i;
        }

        list_iterator operator--() {
            if (p->getPrv()==nullptr) throw exception();
            p = p->getPrv();
            return p;
        }

        node<T> *operator--(int) {
            if (p->getPrv()==nullptr) throw exception();
            list_iterator i = p;
            p = p->getPrv();
            return i;
        }

        bool operator==(const list_iterator &source) const {
            return p == source.p;
        }
        bool operator != (const list_iterator &source) const {
            return p!=source.p;
        }

        list_iterator &operator + (int idx) {
            for (int i=0;i<idx;++i)
                ++*(this);
            return *this;
        }
        list_iterator &operator - (int idx) {
            for (int i=0;i<=idx;++i)
                --*(this);
            return *this;
        }
        T operator*() {
            return p->getVal();
        }
        T* operator -> () {
            return &p;
        }
    };

    void pushBack(T value);

    void insert(T value, list_iterator it) ;

    list_iterator erase(list_iterator it) ;

    void printAll() ;

    inline int getSize();

    List<T>& operator = (const List<T> &source);

    list_iterator begin() {
        list_iterator it(head);
        return it;
    }

    list_iterator end() {
        list_iterator it(dummy);
        return it;
    }
    ~List();
};
#endif //S1P1_LIST_H
