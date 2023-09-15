class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    bool isValid(int x, int y, vector<vector<int>>& board) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }

    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int countLiveNeighbors = 0;
                for (auto direction : directions) {
                    int newRow = row + direction[0];
                    int newCol = col + direction[1];

                    if (isValid(newRow, newCol, board) && (board[newRow][newCol] == 1 || board[newRow][newCol] == -1))
                        countLiveNeighbors++;
                }

                if (board[row][col] == 1 && (countLiveNeighbors < 2 || countLiveNeighbors > 3))
                    board[row][col] = -1;
                else if (board[row][col] == 0 && countLiveNeighbors == 3)
                    board[row][col] = 2;
            }
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == -1)
                    board[row][col] = 0;
                else if (board[row][col] == 2)
                    board[row][col] = 1;
            }
        }
    }
};
