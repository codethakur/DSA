class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, -1); // Initialize v with -1
        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];

            while (!st.empty() && nums[st.top()] < num) {
                v[st.top()] = num;
                st.pop();
            }

            if (i < n) {
                st.push(i);
            }
        }

        return v;
    }
};
/*
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> v;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        if (st.empty()) {
            v.push_back(-1);
        } else if (st.top() < nums[i]) {
            v.push_back(st.top());
        } else {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                v.push_back(-1);
            } else {
                v.push_back(st.top());
            }
        }
        st.push(nums[i]);
    }

    reverse(v.begin(), v.end());
    return v;
}

*/
