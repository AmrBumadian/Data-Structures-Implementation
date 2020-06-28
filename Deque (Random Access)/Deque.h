#ifndef DEQUE__RANDOM_ACCESS__DEQUE_H
#define DEQUE__RANDOM_ACCESS__DEQUE_H

template<class T>
class Deque {
private:
    int capacity[3];
    int size[3];
    T **array = new T *[3];

    void copyDeque(const Deque<T> &other);

    void deleteAll();

public:
    Deque();

    Deque(int size, T value);

    Deque(const Deque<T> &other);

    ~Deque();

    Deque<T> &operator=(const Deque<T> &other);

    void clear();

    void pushFront(T value);

    void pushBack(T value);

    void popFront();

    void popBack();

    T operator [] (int index) const;

    int length() const;

    T front() const;

    T back() const;

    void print() const;
};


#endif //DEQUE__RANDOM_ACCESS__DEQUE_H
