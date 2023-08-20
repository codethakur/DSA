class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string word = "";
        for(int i=0; i<s.length(); i++)
        {
            while(i<s.length() && !isspace(s[i]))
            {
                word+=s[i];
                i++;
            }
            if(!word.empty())
            {
                st.push(word);
                word="";
            }  
        }
        string result="";
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
            if(!st.empty())
            {
                result+=" ";
            }
        }
        return result;
    }
};
