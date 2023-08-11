class Solution {
public:
    string reverseWords(string s) {
        string reverseword;
        string word;
        for(char c:s)
        {
            if (c == ' ')
            {
                if(!word.empty())
                {
                    if(!reverseword.empty())
                    {
                        reverseword = ' ' + reverseword;
                    }
                    reverseword = word + reverseword;
                    word="";
                }
            }else{
                word+=c;
            }
        }
        if(!word.empty())
                {
                    if(!reverseword.empty())
                    {
                        reverseword = ' ' + reverseword;
                    }
                    reverseword = word + reverseword;
                }
        return reverseword;
    }
};
