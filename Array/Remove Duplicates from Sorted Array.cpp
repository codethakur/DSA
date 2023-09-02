class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0; i<nums.size()-1;){
            if(nums[i]==nums[i+1]){
               nums.erase(nums.begin()+i+1);
            }
            else
            i++;
        }
        return nums.size();
    }
};
/*
it increments the index i by 1.
The time complexity of the erase operation in a vector is O(n), where n is the number of elements after the erased element. In the worst case, when you have to erase elements consecutively, this results in quadratic time complexity.

So, the overall time complexity of this code is O(n^2), where n is the number of elements in the nums vector
*/

 class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int uniqueCount = 1;
        for(int i=1; i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]){
                nums[uniqueCount] = nums[i];
                ++uniqueCount;
            }
        }
        return uniqueCount;
    }
};
//he loop runs in O(n) time, where n is the number of elements in the nums vector.
