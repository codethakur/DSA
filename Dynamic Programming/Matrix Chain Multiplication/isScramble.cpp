class Solution {
public:
    unordered_map<string, bool>mp;
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;

        if (s1.length() == 0 && s2.length() == 0) return true;

        if (s1.compare(s2) == 0) return true;

        if (s1.length() <= 1) return false;
        
        string key = s1;
        key.push_back(' ');
        key.append(s2);

        if(mp.find(key)!= mp.end()){
            return mp[key];
        }

        bool flag = false;

        for (int i = 1; i < s1.length(); i++) {
            bool condition1 = (isScramble(s1.substr(0, i), s2.substr(s2.length() - i, i)) &&
                               isScramble(s1.substr(i, s1.length() - i), s2.substr(0, s2.length() - i)));

            bool condition2 = (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                               isScramble(s1.substr(i, s1.length() - i), s2.substr(i, s2.length() - i)));

            if (condition1 || condition2) {
                flag = true;
                break;
            }
        }
        return mp[key]=flag; 
    }
};
