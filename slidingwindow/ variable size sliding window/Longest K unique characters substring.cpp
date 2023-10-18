//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int i=0, j=0;
    int mx = INT_MIN;
    unordered_map<char, int> mp;
    while (j < s.size())
    {
        mp[s[j]]++;
        if (mp.size() < k) j++;
        else if (mp.size() == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return (mx == INT_MIN) ? -1 : mx;
    }
};
