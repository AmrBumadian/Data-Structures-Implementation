#include <bits/stdc++.h>
using namespace std;
#ifndef S1P1_NODE_H
#define S1P1_NODE_H

template<typename T>
class node {
    node<T> *nxt;
    node<T> *prv;
    T value;
public:
    node() : nxt(nullptr), prv(nullptr) {}

    node(T val) : value(val), nxt(nullptr), prv(nullptr) {}

    inline void setNxt(node<T> *location) {
        nxt = location;
    }

    inline void setPrv(node<T> *location) {
        prv = location;
    }

    inline node<T> *getNxt() { return nxt; }

    inline node<T> *getPrv() { return prv; }

    inline void setVal(T val) { this->value = val; }

    inline T getVal() { return value; }
};

#endif //S1P1_NODE_H
