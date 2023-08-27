//First and last occurrences of x
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>result = {-1,-1};
        
        unordered_map<int, vector<int>>mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        auto it=mp.find(x);
        if(it!=mp.end())
        {
            result[0] = it->second[0];
            result[1] = it->second.back();
        }
        return result;
    }
};
