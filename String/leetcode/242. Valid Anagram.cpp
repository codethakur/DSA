class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char, int>cheacked;

        for(auto c:s){
            cheacked[c]++;
        }
        for(auto c:t){
            if(cheacked.find(c)==cheacked.end() || cheacked[c]==0) return false;
            cheacked[c]--;
        }
        return true;
    }
};
