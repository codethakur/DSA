class Solution {
public:
    void solve(vector<int>& output, vector<int>& input, int index, vector<vector<int>>& result) {
        if (index == input.size()) {
            result.push_back(output);
            return;
        }

        // Exclude the current element
        solve(output, input, index + 1, result);

        // Include the current element
        output.push_back(input[index]);
        solve(output, input, index + 1, result);

        // Backtrack to the previous state (remove the current element from output)
        output.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> output;
        solve(output, nums, 0, result);
        return result;
    }
};
