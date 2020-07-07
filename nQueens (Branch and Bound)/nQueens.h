#ifndef QUEENS_NQUEENS_H
#define QUEENS_NQUEENS_H

#include <iostream>

using namespace std;

class nQueens {

private:
    bool solution;
    int noOfSolutions;
    int noOfQueens;
    int *queensInRow; // pointer to queens setting array

    bool *columns;

    bool *URtoBL; // array represents the diagonals going from the Upper Right to Bottom Left;
	bool *ULtoBR; // array represents the diagonals going from the Upper left to Bottom right;

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
		// if the column is taken or any of the diagonals is taken, cannot place the queen
        if (URtoBL[k + i] || ULtoBR[k - i + (noOfQueens - 1)] || columns[i]) {
            return false;
        }
        return true;
    }

public:

    nQueens(int queens = 8) { // works for any number of queens
        solution = false;
        noOfQueens = queens;
        noOfSolutions = 0;
        queensInRow = new int[queens]; // queensInRow[i] value represents the column where the i-th queen on the i-th row should be.

        URtoBL = new bool[2 * queens - 1], ULtoBR = new bool[2 * queens - 1]; // each array is double the size-1 as diagonals are numbered 0-2*noOfQueens-1
        columns = new bool[queens]; // indicate if the column is already taken

        for (int i = 0; i < 2 * queens - 1; ++i) { // initialize arrays to false
            URtoBL[i] = ULtoBR[i] = 0;
            if (i < queens) {
                columns[i] = 0;
            }
        }
    }

// k represents the row number (same as the queen number)
    bool queenPlacement(int k) {
        for (int i = 0; i < noOfQueens; ++i) { // column no.
            // check that the current queen at row k can be put at column i without being attacked by any other queen
            if (canPlaceQueen(k, i)) {
                queensInRow[k] = i; // place the kth queen at the row k and column i
                URtoBL[k + i] = ULtoBR[k - i + (noOfQueens - 1)] = 1; // set them as taken
                columns[i] = 1;
                if (k == noOfQueens - 1) { // if all the queens have been placed
                    ++noOfSolutions; // increment the number of solutions
                    printSolution(); // print current solution
                    solution = 1; 
                } else {
                    queenPlacement(k + 1); // place the next queen
                }
                URtoBL[k + i] = ULtoBR[k - i + (noOfQueens - 1)] = 0; // backtrack the changes
                columns[i] = 0;
            }
        }
        return solution; // if only one solution exists returns true
    }

    int solutionCount() {
        return noOfSolutions;
    }

    ~nQueens() {
        delete[] queensInRow;
    }

};


#endif //QUEENS_NQUEENS_H
