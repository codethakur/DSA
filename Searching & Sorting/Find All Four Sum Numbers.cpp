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
vector<vector<int>> fourSum(vector<int> &arr, int k) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int targetSum2 = k - (arr[i] + arr[j]);

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                int twoSum = arr[left] + arr[right];

                if (twoSum == targetSum2) {
                    vector<int> temp = {arr[i], arr[j], arr[left], arr[right]};
                    ans.push_back(temp);

                    // Move the pointers and avoid duplicates
                    left++;
                    right--;
                    while (left < right && arr[left] == arr[left - 1])
                        left++;
                    while (left < right && arr[right] == arr[right + 1])
                        right--;
                } else if (twoSum < targetSum2) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return ans;
// }
// O(n^2 * n) ~ n^3

