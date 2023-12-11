/*You are required to complete this method*/

class Solution{
  public:
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
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int maxRectangleArea = 0;

        // Convert the binary matrix M to a histogram and calculate the maximum area
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && M[i][j] == 1) {
                    M[i][j] += M[i - 1][j];
                }
            }
            maxRectangleArea = max(maxRectangleArea, getMaxArea(M[i], m));
        }

        return maxRectangleArea;
    }
};
