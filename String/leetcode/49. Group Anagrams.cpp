class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        // The loop should go through the strs vector, not the mp size
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end()); // Sort the temp string, not strs[i]
            mp[temp].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            result.push_back(it->second);
        }
        
        return result;
    }
};

/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (const string& str : strs) {
            // Create a character count array of size 26 (assuming lowercase letters only)
            int charCount[26] = {0};
            
            // Count the occurrences of each character in the string
            for (char c : str) {
                charCount[c - 'a']++;
            }
            
            // Create a unique key using the character count array
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(charCount[i]) + "#"; // Using "#" as a separator
            }
            
            // Add the string to the corresponding group in the map
            mp[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            result.push_back(it->second);
        }
        
        return result;
    }
};*/
