
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0; 
        int leftsum =0;
        for(auto num:nums) sum+=num;
        for(int i=0; i<nums.size(); i++)
        {
            if(leftsum==sum-leftsum-nums[i]) return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};
//Time Complexity: O(n)
//Space Complexity: O(1)
