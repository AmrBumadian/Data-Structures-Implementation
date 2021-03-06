#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

int main() {
    Queue<int> q(5);
    for (int i = 0; i < 6; ++i) {
        q.push(i + 1);
    }
    q.pop();
    q.push(6);
    cout << q.front() << " " << q.back();

    cout << "\n------------------------------------------\n";
    Queue<int> t(q);
    q.pop();
    q.push(10);
    cout << q.front() << " " << q.back();

    cout << "\n------------------------------------------\n";
    Queue<int> a(5);
    for (int i = 0; i < 5; ++i) {
        a.push(i + 1);
    }
    cout << a.front() << " " << a.back() << endl;

    cout << a.pop() << endl;
    cout << a.pop() << endl;
    a.push(6);
    a.push(19);

    a.resize(6);
    cout << a.front() << " " << a.back();


    return 0;
}
