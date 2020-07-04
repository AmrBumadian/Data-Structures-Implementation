#ifndef QUEENS_NQUEENS_H
#define QUEENS_NQUEENS_H

#include <iostream>

using namespace std;

class nQueens {

private:

    int noOfSolutions;
    int noOfQueens;
    int *queensInRow; // pointer to queens setting array

    void printSolution() {
        cout << "(";
        for (int i = 0; i < noOfQueens - 1; ++i) {
            cout << queensInRow[i] << ", ";
        }
        cout << queensInRow[noOfQueens - 1] << ")" << endl;
    }

    /* if there is a queen that is on the same column
     * or (abs(queensInRow[j] - i) == abs(j - k))) which is true if they are on the same diagonal
     * then return false, cannot place the queen on this cell
     * else return true
     */
    bool canPlaceQueen(int k, int i) {
        for (int j = 0; j < k; ++j) { // row number
            if ((queensInRow[j] == i) || (abs(queensInRow[j] - i) == abs(j - k))) {
                return false;
            }
        }
        return true;
    }

public:

    nQueens(int queens = 8) { // works for any number of queens
        noOfQueens = queens;
        noOfSolutions = 0;
        queensInRow = new int[queens]; // queensInRow[i] value represents the column where the i-th queen on the i-th row should be.
    }

    // k represents the row number (same as the queen number)
    void queenPlacement(int k) {
        for (int i = 0; i < noOfQueens; ++i) { // column no.
            if (canPlaceQueen(k,
                              i)) { // check that the current queen at row k can be put at column i without being attacked by any other queen
                queensInRow[k] = i; // place the kth queen at the row k and column i
                if (k == noOfQueens - 1) { // if all the queens have been placed
                    ++noOfSolutions; // increment the number of solutions
                    printSolution(); // print current solution
                } else {
                    queenPlacement(k + 1); // place the next queen
                }
            }
        }
    }

    int solutionCount() {
        return noOfSolutions;
    }

    ~nQueens() {
        delete[] queensInRow;
    }

};


#endif //QUEENS_NQUEENS_H
