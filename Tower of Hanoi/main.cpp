#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>

using namespace std;

vector<stack<int>> needles;

void moveDisk(int count, int needle1, int needle3, int needle2) {
    if (count > 0) {
        moveDisk(count - 1, needle1, needle2, needle3);

        cout << "Moving disk " << count << " from " << needle1 << " to " << needle3 << "." << endl;
        needles[needle3 - 1].push(needles[needle1 - 1].top());
        needles[needle1 - 1].pop();
        moveDisk(count - 1, needle2, needle3, needle1);
    }
}

int main() {
    needles.emplace_back(stack<int>());
    needles.emplace_back(stack<int>());
    needles.emplace_back(stack<int>());

    cout << "Enter number of disks: ";
    int n;
    cin >> n;
    for (int i = n; i >= 1; --i) {
        needles[0].push(i);
    }
    moveDisk(n, 1, 3, 2);

    while (needles[2].size() != 0) {
        cout << setw(64);
        cout << string(needles[2].top(), '-') << needles[2].top() << string(needles[2].top(), '-') << endl;
        needles[2].pop();
    }
    return 0;
}
