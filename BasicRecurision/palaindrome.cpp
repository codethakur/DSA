#include<bits/stdc++.h>
using namespace std;

bool fun(int i, string &s)
{
    if(i>=s.size()/2) return true;
    if(s[i] != s[ s.size()-i-1] ) return false;

    return fun(i+1,s);
}
int main()
{
    string s = "level";
    cout<<fun(0,s);
    return 0;
}

/*leetcode-> https://leetcode.com/problems/valid-palindrome/
//125. Valid Palindrome
class Solution {
public:
    bool fun(int i, string &str)
    {
        if(i>=str.size()/2) return true;
        if(str[i] != str[ str.size()-i-1] ) return false;

        return fun(i+1,str);
    }
    bool isPalindrome(string s) {
         string str;

        for(int i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z') str.push_back(tolower(s[i]));
            else if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9') str.push_back(s[i]);
        }
        return fun(0,str);
    }
};*/
