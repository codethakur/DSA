#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        int closestSum = INT_MAX;
        int minDiff = INT_MAX;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    int diff = std::abs(sum - target);

                    if (diff < minDiff) {
                        minDiff = diff;
                        closestSum = sum;
                    }
                }
            }        //O(n^3);
        }

        return closestSum;
    }
};
//~~~~~~~~~~~~~`````````````````````~~~~~~~~~~~~~~~~~~~```````````````````~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        int closestSum = INT_MAX;
        int minDiff = INT_MAX;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = std::abs(sum - target);

                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }

                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }            // time complexity of O(n^2)

        return closestSum;
    }
};

