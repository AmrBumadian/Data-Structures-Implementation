#include <iostream>
#include "Deque.h"

using namespace std;


int main() {
    Deque<int> d;

    cout << "First Test: Push - Pop - getBack\n";
    for (int i = 0; i < 100; ++i) {
        d.push(i);
    }
    cout << "Current size: " << d.getSize() << "\n";
    for (int i = 0; i < 100; ++i) {
        cout << d.getBack() << " ";
        d.pop();
    }
    cout << endl;
    cout << "Current size: " << d.getSize() << "\n";
    cout << endl;

    cout << "Second Test: Inject - Eject - getFront\n\n";
    for (int i = 0; i < 100; ++i) {
        d.inject(i);
    }

    cout << "Current size: " << d.getSize() << "\n";
    for (int i = 0; i < 100; ++i) {
        cout << d.getFront() << " ";
        d.eject();
    }
    cout << endl;
    cout << "Current size: " << d.getSize() << "\n";
    return 0;
}
