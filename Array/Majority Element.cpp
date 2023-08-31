class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
      unordered_map<int, int>cheack;
      for(auto num:nums){
          cheack[num]++;
      }
      for(auto num:cheack){
          if(num.second>n/2)
            return num.first;
      }
      return 0;

    }
};
