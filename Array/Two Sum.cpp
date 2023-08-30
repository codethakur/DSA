#include<bits/stdc++.h>
using namespace std;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j}; 
            }
        }
        //Time Complexity: O(n^2)
        //Space Complexity: O(n)
        return {}; 
    }
/*vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.count(target-nums[i]))
                return {i,mp[target-nums[i]]};
            mp[nums[i]] = i;    
        }
        return {};
    }
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    */

    }
int main() {
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> result = twoSum(nums, target);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
