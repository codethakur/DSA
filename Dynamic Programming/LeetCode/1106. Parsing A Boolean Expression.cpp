class Solution {
public:
    bool solve(string s, int &i) {
        char c = s[i++];
        if (c == 't') return true;
        if (c == 'f') return false;
        if (c == '!') {
            i++; // Skip '('
            bool val = solve(s, i);
            i++; // Skip ')'
            return !val;
        }
        bool ans = (c == '&'); // Initialize ans based on operator
        i++; // Skip '('
        while (s[i] != ')') {
            bool val = solve(s, i);
            if (c == '&') ans &= val;
            else if (c == '|') ans |= val;
            else if (c == '^') ans ^= val;
            if (s[i] == ',') i++; // Move to the next operand
        }
        i++; // Skip ')'
        return ans;
    }
    
    bool parseBoolExpr(string expression) {
        int i = 0;
        return solve(expression, i);
    }
};
