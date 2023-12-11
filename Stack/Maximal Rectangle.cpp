class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxRectangleArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Update height for each column
                if (matrix[i][j] == '1') {
                    heights[j] = heights[j] + 1;
                } else {
                    heights[j] = 0;
                }
            }

            // Calculate max rectangle area for the current row
            maxRectangleArea = max(maxRectangleArea, getMaxArea(heights.data(), m));
        }

        return maxRectangleArea;
    }
    private:
    int getMaxArea(int arr[], int n) {
        stack<int> st;
        vector<int> leftsmall(n), rightsmall(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            leftsmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

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
};
