class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int> v;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                v.push_back(-1);
            } else if (st.top() < a[i]) {
                v.push_back(st.top());
            } else {
                while (!st.empty() && st.top() >= a[i]) {
                    st.pop();
                }
                v.push_back(st.empty() ? -1 : st.top());
            }

            st.push(a[i]);
        }

        return v;
    }
};
