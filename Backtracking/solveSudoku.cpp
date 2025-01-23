#include <vector>
using namespace std;

class Solution {
private:
    // Function to check if placing `num` at board[row][col] is valid
    bool isSafe(char num, int row, int col, vector<vector<char>>& board) {
        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num) {
                return false;
            }
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }

        // Check 3x3 subgrid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    // Backtracking function to solve Sudoku
    bool placeNumber(int rowInd, int colInd, vector<vector<char>>& board) {
        if (rowInd == 9) { // All rows processed
            return true;
        }

        if (colInd == 9) { // Move to the next row
            return placeNumber(rowInd + 1, 0, board);
        }

        if (board[rowInd][colInd] != '.') { // Skip pre-filled cells
            return placeNumber(rowInd, colInd + 1, board);
        }

        for (char num = '1'; num <= '9'; num++) {
            if (isSafe(num, rowInd, colInd, board)) {
                board[rowInd][colInd] = num; // Place the number
                if (placeNumber(rowInd, colInd + 1, board)) { // Recurse
                    return true;
                }
                board[rowInd][colInd] = '.'; // Backtrack
            }
        }

        return false; // No valid placement found
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        placeNumber(0, 0, board);
    }
};

int main()
{
    
}
