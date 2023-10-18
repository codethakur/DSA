class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n==0)
            return 0;
        unordered_map<int, int>Mymap;
        int currSum=0;
        int i=0;
        int count=0;

        while(i<n)
        {
            currSum+=nums[i];
            if(currSum==k)
                count+=1;
            if(Mymap.find(currSum-k)!=Mymap.end())
                count+=Mymap[currSum-k];

            Mymap[currSum]+=1; 
            i+=1;   
        }
        return count;
    }
};
