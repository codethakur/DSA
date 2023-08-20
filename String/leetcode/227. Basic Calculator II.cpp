class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if(n==0) return 0;
        stack<int>st;
        int currentNumber = 0;
        int operationed = '+'; // initially, because at end of cal we have add all cal

        for(int i=0; i<n;i++)
        {
            char currentChar = s[i];
            if(isdigit(currentChar))
            {
                currentNumber = (currentNumber*10) + (currentChar-'0');
            }
            if(!isdigit(currentChar) && !iswspace(currentChar) || i==n-1)
            {
                if(operationed == '-')
                {
                    st.push(-currentNumber);
                }
                else if(operationed =='+')
                {
                    st.push(currentNumber);
                }
               else if(operationed=='*')
                {
                    int stTop = st.top();
                    st.pop();
                    st.push(stTop * currentNumber);
                }
                else if(operationed == '/')
                {
                    int stTop = st.top();
                    st.pop();
                    st.push(stTop / currentNumber);
                }
            operationed = currentChar;
            currentNumber = 0;
            }
        }
        int result = 0;
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        return result;
    }
};
