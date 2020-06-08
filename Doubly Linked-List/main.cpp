#include <bits/stdc++.h>
#include "List.h"
#include "List.cpp"

using namespace std;

int main() {
    List<int> lst;
    for (int i=1;i<=5;++i)
        lst.insert(i,lst.end());
    lst.printAll();
    lst.insert(6,lst.begin()+3);
    lst.printAll();
    List<int>::list_iterator it = lst.erase(lst.end()-2);
    cout<<*it;
    //List<int> lst2(10,100);
    /*for (int i = 0; i < 100; ++i)
        lst.insert(i, lst.end());
    for (int i = 99; i >= 0; --i)
        lst.pushBack(i);
    lst.printAll();
    cout << "***************************************************************" << "\n";
    for (int i = 0; i < 50; i++) {
        lst.erase(lst.end());
    }
    lst.printAll();
    cout << "***************************************************************" << "\n";*/
   /* for (int i = 1; i <= 5; ++i)
        lst.insert(i, lst.end());
    List<int> nlst(lst);
    for (int i = 1; i <= 5; ++i) {
        nlst.insert(i+5,lst.end());
    }
    nlst = lst;
    nlst.printAll();*/
    return 0;
}
