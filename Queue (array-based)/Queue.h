#ifndef QUEUE__ARRAY_BASED__QUEUE_H
#define QUEUE__ARRAY_BASED__QUEUE_H

template<class T>
class Queue {
private:
    T *array;
    int capacity;
    int length;
    int f;
    int b;

    void copy(const Queue<T> &other);

public:
    Queue(int size);

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


#endif //QUEUE__ARRAY_BASED__QUEUE_H
