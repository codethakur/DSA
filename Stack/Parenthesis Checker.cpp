#include <stack>
#include <string>

class Solution {
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x) {
        // Your code here
        stack<char> st;
        for (char c : x) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // Check if the stack is empty before using top() to avoid runtime errors.
                if (st.empty() ||
                    (c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop(); // Corrected: pop the opening bracket from the stack.
            }
        }
        // The final check should be after the loop completes.
        return st.empty();
    }
};
