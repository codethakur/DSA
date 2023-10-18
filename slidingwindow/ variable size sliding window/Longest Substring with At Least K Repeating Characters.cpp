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
/////////////////leetcode//////////////////////////////

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        return longestSubstringHelper(s, 0, n - 1, k);
    }

    int longestSubstringHelper(string &s, int start, int end, int k) {
        if (end - start + 1 < k) {
            return 0;
        }
        
        unordered_map<char, int> mp;
        for (int i = start; i <= end; ++i) {
            mp[s[i]]++;
        }

        for (int i = start; i <= end; ++i) {
            if (mp[s[i]] < k) {
                int left = longestSubstringHelper(s, start, i - 1, k);
                int right = longestSubstringHelper(s, i + 1, end, k);
                return max(left, right);
            }
        }

        return end - start + 1;
    }
};
