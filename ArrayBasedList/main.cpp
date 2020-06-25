#include<bits/stdc++.h>
#include "AList.h"
#include "AList.cpp"

using namespace std;

int main() {
    AList<int> l1;
    AList<int> l2(5);
    AList<int> l3(10, 5);

    cout << l1.getSize() << " " << l1.getLength() << endl;
    cout << l2.getSize() << " " << l2.getLength() << endl;
    cout << l3.getSize() << " " << l3.getLength() << endl;


    l2.insert(9);
    l2.print();

    cout << l2.isEmpty() << " " << l2.isFull() << endl;
    cout << l3.isEmpty() << " " << l3.isFull();

    l3.remove(5);
    l3.print();
    int x = 6;
    l3.retrieveAt(5, x);
    cout << x << endl;

}