class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
          unordered_map<char , int> mp;
        //taking freq of element of s1
        for(auto it: s1) mp[it]++;
        vector<int> ans;
        int cnt = mp.size();
        int i = 0; 
        int j = 0;
        int k = s1.size();
        //standard question of fixed size sliding window 
        while(j < s2.size()){
            //doing calculation 
            if(mp.find(s2[j]) != mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]] == 0) cnt--;
            }
             //when we don't hit the window
            if(j-i+1 < k) j++;
             //when hit the window
            else if(j-i+1 == k){
                if(cnt == 0) ans.push_back(i);
                if(mp.find(s2[i]) != mp.end()){
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1){
                        cnt++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
