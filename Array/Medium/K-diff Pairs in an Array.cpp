//using two pointers 
//overall time complexity O(n * log(n)).
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = 1;
        int cnt = 0;
        k = abs(k);
        
        while (l <= r && r < nums.size()) {
            int diff = nums[r] - nums[l];
            if (diff == k && l != r) {
                cnt++;
                l++;
                r++;
                // Move l and r to avoid counting duplicates
                while (l < nums.size() && nums[l] == nums[l - 1])
                    l++;
                while (r < nums.size() && nums[r] == nums[r - 1])
                    r++;
            } else if (diff > k) {
                l++;
                if (l == r)
                    r++;
            } else {
                r++;
            }
        }
        
        return cnt;
    }
};
/////////////////////////////////
// using binary search overall time complexity O(n * log(n)).
class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Return -1 if the target is not found.
    }
    
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> pairs; // Use a set to store unique pairs.
        
        for (int i = 0; i < nums.size(); i++) {
            int target = nums[i] + k;
            int foundIndex = binarySearch(nums, target);
            if (foundIndex != -1 && foundIndex != i) {
                pairs.insert({nums[i], nums[foundIndex]});
            }
        }
        
        return pairs.size();
    }
};




//~~~~~~~~~~~~~``````````````````````~~~~~~~~~~~~~~~~~~~
// using map
//overall time complexity O(n).
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0; // The absolute difference can't be negative, so return 0.
        }

        unordered_map<int, int> mp;
        int count = 0;

        for (int num : nums) {
            mp[num]++;
        }

        for (const auto& pair : mp) {
            if (k == 0) {
                // Count the number of elements that appear more than once.
                if (pair.second >= 2) {
                    count++;
                }
            } else {
                // Count the pairs where num + k exists in the map.
                if (mp.find(pair.first + k) != mp.end()) {
                    count++;
                }
            }
        }

        return count;
    }
};
