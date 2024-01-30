#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq;  // Using max heap
        for(auto i = mp.begin(); i != mp.end(); i++) {
            pq.push({i->second, i->first});
        }

        vector<int> ans;
        while(k > 0 && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = obj.topK(nums, k);
    
    cout << "Output: {";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    return 0;
}
