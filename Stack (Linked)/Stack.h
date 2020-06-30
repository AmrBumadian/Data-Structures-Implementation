#ifndef STACK__LINKED__STACK_H
#define STACK__LINKED__STACK_H

template<class T>
class Node {
public:
    T value;
    Node<T> *next;

    Node() {
        next = nullptr;
    }

    Node(T value) {
        this->value = value;
        next = nullptr;
    }
};

template<class T>
class Stack {
private:
    Node<T> *head;
    int length;

    void copy(const Stack<T> &other);

public:
    Stack();

    Stack(const Stack<T> &other);

    Stack<T> &operator=(const Stack<T> &other);

    ~Stack();

    void push(T value);

    T pop();

    T top();

    void clear();

    int size();

    bool empty();

};


#endif //STACK__LINKED__STACK_H
