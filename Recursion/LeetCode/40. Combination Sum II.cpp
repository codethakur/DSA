class Solution {
public:
    void solv(vector<int>& candidates, int target, int start, vector<int>& output, vector<vector<int>>& result)
    {
        if (target < 0)return;
      //  if (start >= candidates.size())return;
        
        if (target == 0) {
            result.push_back(output);
            return;
        }   
        for (size_t i = start; i < candidates.size(); i++)  // Update this line

        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;  // Skip duplicates
            output.push_back(candidates[i]);
            solv(candidates, target - candidates[i], i+1, output, result);
            output.pop_back();
            //solv(candidates, target, start + 1, output, result);
        }    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>result;
        vector<int>output;
        solv(candidates, target, 0,output,result);
        return result;

    }
};
