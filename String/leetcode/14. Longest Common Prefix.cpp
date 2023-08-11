class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string commonPrefix = strs[0];  // Initialize with the first string

        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (j < commonPrefix.size() && j < strs[i].size() && commonPrefix[j] == strs[i][j]) {
                ++j;
            }
            commonPrefix = commonPrefix.substr(0, j);  // Update common prefix
        }

        return commonPrefix;
    }
};
