class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int sum = 0;
        unordered_map<int, int>map;
        
        map[0]++;
        for(auto x:nums)
        {
            sum+=x;
            if(map[(sum%k+k)%k]>0){
                count+=map[(sum%k+k)%k];
            }
            map[(sum%k+k)%k]++;
        }
        return count;
    }
};
