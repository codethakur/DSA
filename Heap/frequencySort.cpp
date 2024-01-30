class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> v;
        for(auto num: nums){
            m[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto val:m){
            pq.push({-(val.second), (val.first)});
        }
        while(!pq.empty()){
            int cnt = -pq.top().first;
            while(cnt--){
                v.push_back(pq.top().second);
            }
            pq.pop();
        }
        return v;
    }
};
