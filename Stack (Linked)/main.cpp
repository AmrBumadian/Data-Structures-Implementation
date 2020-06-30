#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

int main() {
    Stack<int> s;

    for (int i = 0; i < 10; ++i) {
        s.push(i);
    }
    for (int i = 0; i < 10; ++i) {
        cout << s.pop() << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; ++i) {
        s.push(i);
    }
    cout << "----------------------------------------------\n";
    Stack<int> t(s);
    for (int i = 0; i < 10; ++i) {
        cout << t.pop() << " ";
    }
    cout<<endl;
    cout << "----------------------------------------------\n";
    t.clear();
    t = s;
    for (int i = 0; i < 10; ++i) {
        cout << t.pop() << " ";
    }

    return 0;
}
