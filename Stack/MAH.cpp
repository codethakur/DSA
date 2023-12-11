 //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<int> st;
        vector<int> leftsmall(n), rightsmall(n);
        
        // Calculate leftsmall array
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            leftsmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        // Clear the stack for re-use
        while (!st.empty()) {
            st.pop();
        }
        
        // Calculate rightsmall array
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            rightsmall[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = rightsmall[i] - leftsmall[i] - 1;
            int area = arr[i] * width;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
