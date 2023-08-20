class Solution {
public:
    string simplifyPath(string path) {
        string token;
        stack<string> st;

        stringstream ss(path);

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // Skip empty tokens and "." tokens
                continue;
            } else if (token == "..") {
                // If the token is ".." and the stack is not empty, pop the top directory
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                // Push valid directory names onto the stack
                st.push(token);
            }
        }

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        // If the result is empty, return the root "/"
        if (result.empty()) {
            result = "/";
        }

        return result;
    }
};
