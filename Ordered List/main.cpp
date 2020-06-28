#include <iostream>
#include "OrderedList.h"
#include "OrderedList.cpp"

using namespace std;

int main() {
    OrderedList<int> l1, l2(5, 5);

    OrderedList<int> l3 = l2;
    l3 = l2;
    l3.print();
    l3.clear();
    l3.print();
    cout << "-------------------------------------------------\n";

    l2.print();
    cout << l2.find(5) << endl;
    l2.removeKey(5);
    l2.print();

    cout << "-------------------------------------------------\n";
    int x = 10;
    for (int i = 0; i < 10; i++) {
        l1.insert(x--);
    }
    l1.print();
    cout << l1.length() << endl;
    for (int i = 0; i < 10; i++) {
        l1.remove(0);
    }
    l1.print();
    cout << l1.length();
}
