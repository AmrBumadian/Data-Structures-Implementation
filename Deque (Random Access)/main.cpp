#include <iostream>
#include "Deque.h"
#include "Deque.cpp"

using namespace std;

int main() {
    Deque<int> d(10, 5);
    d.print();
    cout << "-------------------------------------------\n";

    d.pushFront(6);
    d.pushFront(6);
    d.pushFront(6);

    d.pushBack(6);
    d.pushBack(6);
    d.pushBack(6);

    d.print();
    cout << d.length() << endl;

    cout << "-------------------------------------------\n";

    d.popFront();
    d.popFront();
    d.popFront();
    d.popBack();
    d.popBack();
    d.popBack();

    d.print();
    cout << d.length() << endl;
    cout << "-------------------------------------------\n";

    for (int i = 0; i < 10; ++i) {
        d.pushFront(i);
    }
    d.print();
    cout << d.length() << endl;
    for (int i = 0; i < 10; ++i) { d.popFront(); }
    cout << d.length() << endl;
    d.print();
    cout << "-------------------------------------------\n";

    for (int i = 0; i < 10; ++i) {
        d.pushFront(i);
    }
    for (int i = 0; i < d.length(); ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
    cout << "-------------------------------------------\n";
    for (int i = 0; i < 10; ++i) {
        d.pushBack(i);
    }
    for (int i = 0; i < d.length(); ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
    cout << "-------------------------------------------\n";
    cout << d.front() << " " << d.back() << endl;
    cout << "-------------------------------------------\n";

    Deque<int> q(d);
    q.print();
    q.clear();
    q = d;
    q.print();
    return 0;
}
