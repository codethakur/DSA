class Solution {
public:
    int dp[502][502];
    int solve(vector<int>& nums, int i, int j){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for(int k = i; k<=j-1; k++){
            int temp = solve(nums,i,k) + solve(nums,k+1,j) + nums[k]*nums[i-1]*nums[j];
            ans = max(ans,temp);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        memset(dp,-1,sizeof dp);
        return solve(nums,1,nums.size()-1); 
    }
};
