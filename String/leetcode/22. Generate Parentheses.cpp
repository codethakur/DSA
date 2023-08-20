class Solution {
public:
    void getsolution(string Opt, int open, int close, vector<string> &result)
    {
        if(open==0 && close == 0)
        {
            result.push_back(Opt);
            return;
        }
        if(open!=0)
        {
            string opt1 = Opt;
            opt1.push_back('(');
            getsolution(opt1, open-1, close,result);
        }
        if(close>open)
        {
            string opt1 = Opt;
            opt1.push_back(')');
            getsolution(opt1, open, close-1,result); 
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int open=n, close=n;
        vector<string> result;
        string Opt;
        getsolution(Opt, open, close, result);

        return result;
    }
};
