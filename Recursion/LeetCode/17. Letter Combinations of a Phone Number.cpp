#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void solv(string& Input, int Index, string& Output, vector<string>& result, unordered_map<char, string>& m) {
        if (Index == Input.size()) {
            result.push_back(Output);
            return;
        }
        char digit = Input[Index];
        string str = m[digit];
        for (int i = 0; i < str.size(); i++) {
            Output.push_back(str[i]);
            solv(Input, Index + 1, Output, result, m);
            Output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string Output;
        vector<string> result;
        if (digits.size() == 0)
            return {};
        unordered_map<char, string> m;  
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        solv(digits, 0, Output, result, m);
        return result;
    }
};
