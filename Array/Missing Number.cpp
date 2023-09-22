class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =  nums.size();

        int expectedSum = (n*(n+1))/2;
        int acctualSum = 0;
        for(auto num:nums){
            acctualSum += num;
        }
        return  expectedSum - acctualSum;
    }
};
