#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

int main() {
    Queue<int> q;
    for (int i = 0; i < 6; ++i) {
        q.push(i + 1);
    }
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        cout << q.pop() << " ";
    }
    cout << endl;
    for (int i = 0; i < 6; ++i) {
        q.push(i + 1);
    }
    q.pop();
    q.push(6);
    cout << q.front() << " " << q.back();

    cout << "\n------------------------------------------\n";
    Queue<int> t(q);
    n = t.size();
    for (int i = 0; i < n; ++i) {
        cout << t.pop() << " ";
    }
    cout << endl;
    q.pop();
    q.push(10);
    cout << q.front() << " " << q.back();


    return 0;
}
