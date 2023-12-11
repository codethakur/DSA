class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> discounts;
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                discounts.push_back(-1);
            } else if (st.top() <= prices[i]) {
                discounts.push_back(st.top());
            } else {
                while (!st.empty() && st.top() > prices[i]) {
                    st.pop();
                }
                discounts.push_back(st.empty() ? -1 : st.top());
            }

            st.push(prices[i]);
        }

        reverse(discounts.begin(), discounts.end());

        for (int i = 0; i < n; i++) {
            if (discounts[i] != -1) {
                prices[i] -= discounts[i];
            }
        }

        return prices;
    }
};
