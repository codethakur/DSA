class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
         int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
    }
};
//```````````````````````````````````
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n; i++){
            if(ans.empty() ||intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};
//O(N*logN) + O(N), where N = the size of the given array.

//`````````````````````````````````````````
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        // Sort intervals based on the start of each interval
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        std::vector<std::vector<int>> merged;

        for (const std::vector<int>& interval : intervals) {
            if (merged.empty() || interval[0] > merged.back()[1]) {
                // If the current interval doesn't overlap with the previous merged interval, add it as is.
                merged.push_back(interval);
            } else {
                // If there is an overlap, merge the current interval with the last merged interval.
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
            }
        }

        return merged; //  O(n log n), 
    }
};
//Time Complexity:  O(n log n),
// Space Complexity: O(n) because the merged vector can potentially contain all n intervals. 
//``````````````````````````````````

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int idx = 0;

       for(int i=1; i<n; i++)
       {
           if(intervals[i][0]<=intervals[idx][1])
           {
               intervals[idx][1] = std::max(intervals[idx][1], intervals[i][1]);
           }
           else{
               idx++;
               intervals[idx] = intervals[i];
           }
       } 
       intervals.resize(idx+1);
       return intervals;
    }
};
//Time Complexity:  O(n log n),
// Space Complexity: O(1)
