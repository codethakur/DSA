class Solution {
public:
    bool isNumber(string s) {
        bool digits = false, eseen = false, dotseen = false;
        int countPluseMinus = 0;

        int n = s.length();
        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                digits = true;
            } else if (ch == '+' || ch == '-') {
                if (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E')) {
                    return false;
                }
                if (countPluseMinus == 2) {
                    return false;
                }
                if (i == n - 1) {
                    return false;
                }
                countPluseMinus++;
            } else if (ch == '.') {
                if (eseen || dotseen) {
                    return false;
                }
                if (i == n - 1 && !digits) {
                    return false;
                }
                if (i > 0 && (s[i - 1] == 'e' || s[i - 1] == 'E')) {
                    return false;
                }
                dotseen = true;
            } else if (ch == 'e' || ch == 'E') {
                if (eseen || !digits || i == n - 1) {
                    return false;
                }
                eseen = true;
                digits = false;  // Reset digits flag for the exponent part
            } else {
                return false;
            }
        }
        return digits; // Make sure there are at least some digits in the input
    }
};
