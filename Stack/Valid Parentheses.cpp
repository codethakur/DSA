class Solution {
public:
unordered_map<char, int> symbols= {{'[',-1},{'(',-2},{'{',-3},{']',1},{')',2},{'}',3},};

    bool isValid(string s) {
        if(s.empty() || s.size()<2)
        {
            return false;
        }
        stack<char> st;

        for(char brackets:s)
        {
            if(symbols[brackets]<0){
                st.push(brackets); 
            }else
            {
                if(st.empty()) return false;
                char Top = st.top();
                st.pop();
                if(symbols[Top] + symbols[brackets] != 0){
                    return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
