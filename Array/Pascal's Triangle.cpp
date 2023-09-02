
//```````````````````````````
class Solution {
public:
    int ncr(int n, int r)
    {
        long long int res = 1;
        for (int i = 0; i < r; i++)
        {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> result;
    
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1); // Initialize each row with 1s.
        
        // Calculate values for the current row.
        for (int j = 1; j < i; j++) {
            row[j] = ncr(i, j);
        }
        
        result.push_back(row);
    }
    
    return result;
    }
};

//`````````````````````
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int row = 0; row < numRows; row++) {
            vector<int> currentRow(row + 1, 1); // Initialize the row with 1s
            for (int col = 1; col < row; col++) {
                currentRow[col] = ans[row - 1][col - 1] + ans[row - 1][col];
            }
            ans.push_back(currentRow);
        }

        return ans;
    }
};
