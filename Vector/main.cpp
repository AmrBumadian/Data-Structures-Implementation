#include <iostream>
#include "Vector.h"
#include "Vector.cpp"

using namespace std;


int main() {
    Vector<int> v1, v2(1000), v3(10000, 5), v4(v2);

    Vector<int> v5;

    v5.resize(10);
    v5.resize(0);
    for (int i = 0; i < 10; ++i) {
        v5.pushBack(i + 1);
    }
    cout << v5.Size() << " " << v5.Capacity() << endl;
    for (int i = 0; i < 10; ++i) {
        v5.erase(0);
        cout << v5.Size() << " " << v5.Capacity() << endl;
    }
    cout << endl;
    cout << v5.Size() << " " << v5.Capacity() << endl;

    cout << "---------------------------------------------------------------------\n";

    v5.insert(0, 1);
    v5.print();

    v5.insert(0, 2);
    v5.print();

    v5.insert(0, 3);
    v5.print();

    v5.insert(1, 4);
    v5.print();

    v5.insert(2, 5);
    v5.print();

    cout << "---------------------------------------------------------------------\n";

    v5.erase(2);
    v5.print();

    v5.erase(1);
    v5.print();

    v5.erase(0);
    v5.print();


    v5.erase(0);
    v5.print();

    v5.erase(0);
    v5.print();


    cout << v5.Size() << " " << v5.Capacity() << endl;


}
