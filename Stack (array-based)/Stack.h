#ifndef STACK_ARRAY_BASED_STACK_H
#define STACK_ARRAY_BASED_STACK_H

template<class T>
class Stack {
private:
    int capacity;
    int length;
    T *array;

    void copyStack(const Stack<T> &other);

public:
    Stack();

    Stack(const Stack<T> &other);

    Stack<T> &operator=(const Stack<T> &other);

    ~Stack();

    void push(T value);

    T pop();

    T top() const;

    bool empty() const;

    bool size() const;

    void clear();

};


#endif //STACK_ARRAY_BASED_STACK_H
