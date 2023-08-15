#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int i = 0, j = 0;
    int ans = 0;
    int mx = 0;
    long long sum = 0;

    while (j < nums.size()) {
        sum = sum + nums[j];  
        if (sum <= k) {       
            mx = max(mx, j - i + 1);  
            j++;
        } else {
            while (sum > k && i <= j) {  
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n); 
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << subarraySum(nums, k);

    return 0;
}
