class Solution {
public:
    unordered_map<string,bool>mp;

    bool Solve(string a, string b) {
        if(a.compare(b) == 0) return true;
        if(a.length() <= 0) return false;

        // string key = a;
        // key.push_back(' ');
        // key.append(b);
         string key = a + " " + b;
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }



        int n = a.length();
        bool flag = false;

        for(int i = 1; i < n; i++) {
            bool case1 = (Solve(a.substr(0, i), b.substr(n - i, i)) && Solve(a.substr(i, n - i), b.substr(0, n - i)));
            bool case2 = (Solve(a.substr(0, i), b.substr(0, i)) && Solve(a.substr(i, n - i), b.substr(i, n - i)));

            if(case1 || case2) {
                flag = true;
                break;
            }
        }

        return mp[key]= flag;
    }
    bool isScramble(string s1, string s2) {
        return Solve(s1, s2);
    }
};
