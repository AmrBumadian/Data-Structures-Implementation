//
// Created by Amr Bumadian on 6/27/2020.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

template<class T>
class Vector {
private:
    T *array;
    int size;
    int capacity;
public:
    Vector();

    Vector(int capacity);

    Vector(int size, T value);

    Vector(const Vector<T> &other);

    Vector<T> &operator=(const Vector<T> &other);

    ~Vector();

    void pushBack(T value);

    void popBack();

    void insert(int index, T value);

    void resize(int newSize);

    void clear();

    void erase(int index);

    T &at(int index);

    T &operator[](int index);

    bool empty();

    int Size();

    int Capacity();

    void print();

};


#endif //VECTOR_VECTOR_H
