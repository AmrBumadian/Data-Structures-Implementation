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
    for (int i = 0; i < 10; ++i) {
        s.push(i);
    }
    cout << "\n-----------------------------------\n";
    Stack<int> t(s);
    for (int i = 0; i < 10; ++i) {
        cout << t.pop() << " ";
    }

    cout << "\n-----------------------------------\n";
    t.clear();
    t = s;
    for (int i = 0; i < 10; ++i) {
        cout << s.pop() << " ";
    }


    return 0;
}
