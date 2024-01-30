class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>q;
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            int first=abs(x-arr[i]);
            q.push({first,arr[i]});
            if(q.size()>k)
            {
                q.pop();
            } 
        }
        while(q.size()!=0)
        {
            pair<int,int>z=q.top();
            ans.push_back(z.second);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
