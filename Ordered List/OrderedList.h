#ifndef ORDERED_LIST_ORDEREDLIST_H
#define ORDERED_LIST_ORDEREDLIST_H

template<class T>
class Node {
public:
    T value;
    Node<T> *next;

    Node() { next = nullptr; }

    Node(T value) : value(value) { next = nullptr; }
};

template<class T>
class OrderedList {
private:
    Node<T> *head;
    Node<T> *last;
    int size;

    void copyList(const OrderedList<T> &other);

public:
    OrderedList();

    OrderedList(int size, T value);

    OrderedList(const OrderedList<T> &other);

    ~OrderedList();

    OrderedList<T> &operator=(const OrderedList<T> &other);

    void insert(T value);

    void remove(int position);

    void removeKey(T key);

    void clear();

    int length() const;

    T front() const;

    T back() const;

    int find(T value) const;

    void print() const;

};


#endif //ORDERED_LIST_ORDEREDLIST_H
