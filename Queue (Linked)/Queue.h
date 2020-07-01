#ifndef QUEUE__LINKED__QUEUE_H
#define QUEUE__LINKED__QUEUE_H

template<class T>
class Node {
public:
    T value;
    Node<T> *next;

    Node() {
        next = nullptr;
    }

    Node(T value) : value(value) {
        next = nullptr;
    }
};

template<class T>
class Queue {
private:
    Node<T> *head, *tail;
    int length;

    void copy(const Queue<T> &other);

public:
    Queue();

    Queue(const Queue<T> &other);

    Queue<T> &operator=(const Queue<T> &other);

    ~Queue();

    void push(T value);

    T pop();

    T front();

    T back();

    int size();

    bool empty();

    void clear();
};


#endif //QUEUE__LINKED__QUEUE_H
