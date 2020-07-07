#include "nQueens.h"

int main() {
    nQueens puzzle1(2);

    bool exist = puzzle1.queenPlacement(0); // start by the first queen at row k=0
    if (!exist) cout << "No solution" << endl;

    return 0;
}
