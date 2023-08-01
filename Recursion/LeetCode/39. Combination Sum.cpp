//Amazon 18 Facebook 12, Microsoft 6, Airbnb 5, Apple 4, Adobe 3, Bloomberg 3, LinkedIn 3, ByteDance 3,




class Solution {
public:
     void solv(vector<int>& candidates, int target, int start, vector<int>& output, vector<vector<int>>& result)
    {
        if (target < 0)return;
        if (start >= candidates.size())return;
        
        if (target == 0) {
            result.push_back(output);
            return;
        }    

        output.push_back(candidates[start]);
        solv(candidates, target - candidates[start], start, output, result);
        output.pop_back();
        solv(candidates, target, start + 1, output, result);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> output;
        solv(candidates, target, 0, output, result);
        return result;
    }
};
