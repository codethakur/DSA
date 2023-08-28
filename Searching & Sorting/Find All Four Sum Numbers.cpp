/*vector<vector<int>> fourSum(vector<int> &arr, int k) {
    int n = arr.size(); 
    set<vector<int>> st; // Using set of vectors to store unique quadruplets
    
    // The loops have some index errors and other issues
    for(int i = 0; i < n - 3; i++) {
        for(int j = i + 1; j < n - 2; j++) {
            for(int p = j + 1; p < n - 1; p++) {
                for(int q = p + 1; q < n; q++) {
                    long long sum = arr[i] + arr[j] + arr[p] + arr[q];
                    if(sum == k) {
                        vector<int> temp = {arr[i], arr[j], arr[p], arr[q]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
*/

// Test Cases Passed: 
// 1164 /1360
// Time Limit Exceeded o(n^4)
//extra space

/*
vector<vector<int>> fourSum(vector<int> &arr, int k) {
    int n = arr.size(); 
    set<vector<int>> st; // Using set of vectors to store unique quadruplets
    
    // The loops have some index errors and other issues
    for(int i = 0; i < n - 3; i++) {
        for(int j = i + 1; j < n - 2; j++) {
            set<int> hashset; // Using set to store values for the current combination
            for(int p = j + 1; p < n; p++) {
                long long sum = arr[i] + arr[j] + arr[p];
                long long fourth = k - sum;
                if(hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {arr[i], arr[j], arr[p], static_cast<int>(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[p]);
            }
        }
    }
    
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
*/
// Test Cases Passed: 
// 1068 /1360
// Time Limit Exceeded O(n^3)*log(m);
//extra space



#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

// }
// O(n^2 * n) ~ n^3

