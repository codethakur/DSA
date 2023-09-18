class Solution {
public:
    vector<vector<int>> ans;  // Change ans to a vector of vectors

    void helper(vector<int>& candidates, int target, int i, int currSum, vector<int>& temp) {
        if (currSum > target) {
            return;
        }
        if (i == candidates.size()) {
            if (currSum == target) {
                ans.push_back(temp);  // Push a copy of temp into ans
            }
            return;
        }

        // Inclusion
        currSum += candidates[i];
        temp.push_back(candidates[i]);
        helper(candidates, target, i, currSum, temp);
        currSum -= candidates[i];
        temp.pop_back();

        // Exclusion
        helper(candidates, target, i + 1, currSum, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates, target, 0, 0, temp);
        return ans;
    }
};
