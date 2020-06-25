
#ifndef ARRAYBASEDLIST_ALIST_H
#define ARRAYBASEDLIST_ALIST_H

template<class T>
class AList {
private:
    int *list;
    int size;
    int length;

public:
    AList();

    AList(int size);

    AList(int size, T value);

    AList(const AList &other);

    const AList<T>& operator=(const AList<T> &other);

    void insert(T value);

    void insertAt(int index, T value);

    T elementAt(int index);

    bool retrieveAt(int index, T &container);

    int getSize() const;

    int getLength() const;

    bool isEmpty() const;

    bool isFull() const;

    void clear();

    void remove(int idx);

    int indexOf(T val);

    void print() const;

    ~AList();
};

#endif //ARRAYBASEDLIST_ALIST_H
