class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0, j = 0, sum = 0;
    int mx = 0;
    while (j < n) {
        sum += nums[j];
        if (sum < k) {
            j++;
        } else if (sum == k) {
            mx = max(mx, j - i + 1);
            j++;
        }
         else if (sum>k){
                     while(sum>k){
                    sum = sum - nums[i];
                    i++;
                    if(sum==k){
                        mx = max(mx,(j-i+1));
                    }
                }
                j++;
        }

    }
    return mx;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)
