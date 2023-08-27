/*
  class Solution {
public:

    int helperFn(vector<int>& nums, int target,int i, int j)
    {
        if(i<0 || j>=nums.size()|| i>j) return -1;
        int mid = i+(j-i)/2;
        int ans = -1;
        if(nums[mid] == target )
        {
            return mid;
        }else{
            ans = max(ans, helperFn(nums,target,mid+1,j));
            ans = max(ans, helperFn(nums, target, i, mid-1));
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int ans = helperFn(nums,target,0,nums.size()-1);
        return ans;
    }
};
*/
class Solution {
public:
    int BinarySearch(vector<int>& nums, int target,int left, int right)
    {
        if(left>right) return -1;

        int mid = left+(right-left)/2;

        if(target==nums[mid]){
            return mid;
        }
        if(nums[left]<=nums[mid])
        {
            if(target>=nums[left] && target<=nums[mid]){
                return BinarySearch(nums, target, left, mid-1);
            }
            return BinarySearch(nums, target,mid+1, right);
        }
        if(target>=nums[mid] && target<=nums[right])
        {
            return BinarySearch(nums, target, mid+1, right);
        }

        return BinarySearch(nums,target, left, mid-1);
    }
    int search(vector<int>& nums, int target) {

        return BinarySearch(nums, target,0,nums.size()-1);
    }
};
