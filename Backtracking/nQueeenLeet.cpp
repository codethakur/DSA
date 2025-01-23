#include<iostream>
#include<vector>
#include<iostream>
bool isValid(std::vector<std::vector<int>>&board, int n, int rowInd, int colInd )
{
    // Check left side of the row
    for (int col = 0; col < colInd; col++) {
        if (board[rowInd][col] == 1) {
            return false;
        }
    }

    // Check upper-left diagonal
    int i = rowInd, j = colInd;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i -= 1; // Move up
        j -= 1; // Move left
    }

    // Check lower-left diagonal
    i = rowInd, j = colInd;
    while (i < n && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i += 1; // Move down
        j -= 1; // Move left
    }

    return true;
}


void placingQueens(std::vector<std::vector<int>>&board, int n, int colInd, 
                   std::vector<int>&temp, std::vector<std::vector<int>>& Result)
{
    if (colInd == n) {
        Result.push_back(temp);
        return;
    }

    for (int rowInd = 0; rowInd < n; rowInd++) {
        if (isValid(board, n, rowInd, colInd)) {
            temp.push_back(rowInd+1);  // Push 0-based row index
            board[rowInd][colInd] = 1;

            placingQueens(board, n, colInd + 1, temp, Result);

            temp.pop_back();
            board[rowInd][colInd] = 0; // Backtrack
        }
    }
}


std::vector<std::vector<int>> NQueens(int n)
{
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    std::vector<int> temp;
    std::vector<std::vector<int>> result;
    placingQueens(board, n, 0, temp, result);
    return result;
}


int main()
{
    int n = 4; // Example with 4 queens
    auto ans = NQueens(n);

    for (int i = 0; i < ans.size(); i++) {
        std::cout << "Solution " << i + 1 << ": [ ";
        for (int j = 0; j < ans[i].size(); j++) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << "]\n"; // Always print the closing bracket
    }

    return 0;
}



