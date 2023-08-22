#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> mp;
    int count = t.size(); // Initialize count with the size of string t

    for (auto ch : t) {
        mp[ch]++;
    }
    
    int mini = INT_MAX;
    int i = 0, j = 0;
    int n = s.size();
    int start = 0; // To keep track of the starting index of the minimum window
    while (j < n) {
        if (mp.find(s[j]) != mp.end()) {
            if (mp[s[j]] > 0) {
                count--;
            }
            mp[s[j]]--;
        }

        while (count == 0) {
            if (j - i + 1 < mini) {
                mini = j - i + 1;
                start = i;
            }

            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    count++;
                }
            }
            i++;
        }

        j++;
    }

    if (mini == INT_MAX) {
        return "";
    } else {
        return s.substr(start, mini);
    }
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}
