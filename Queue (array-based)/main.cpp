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


    return 0;
}
