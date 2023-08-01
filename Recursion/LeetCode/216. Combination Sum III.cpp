class Solution {
public:
    void solv(int k, int n, int start, vector<int>output, vector<vector<int>>&result)
    {
        if(k==0 && n==0){
            result.push_back(output);
            return;
        }
        for(int i=start; i<=9; i++)
        {
            if(n-i<0) break;
            output.push_back(i);
            solv(k-1,n-i, i+1, output,result);
            output.pop_back();

        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
         
         vector<int>output;
         vector<vector<int>>result;
         solv(k,n,1,output,result);

         return result;
    }
};
