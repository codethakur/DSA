class Solution {
public:
vector<int> ngr(vector<int> &nums2){
    int n=nums2.size();
    stack<int> st;
    vector<int>v;
    for(int i=n-1;i>=0;i--){
        if(st.empty())
        v.push_back(-1);
        else if(st.size()>0 && st.top()>nums2[i])
            v.push_back(st.top());
        else if(st.size()>0 && st.top()<=nums2[i])
        {
            while(st.size()>0 && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.size()==0)
            {
                v.push_back(-1);
            }
            else{
                v.push_back(st.top());
            }
        }

        st.push(nums2[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v=ngr(nums2);
        vector<int> ans(nums1);
       unordered_map<int,int> mp; 
       for(int i=0;i<nums2.size();i++){
        mp[nums2[i]]=v[i];
       }
       for(int i=0;i<nums1.size();i++){
          ans[i]=mp[nums1[i]];
       }
       return ans;
    }
};
