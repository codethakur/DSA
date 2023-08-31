class Solution {
public:
    int fun(int ind, int buy, vector<int>& prices, int n )
    {
        long profit=0;
        if(ind==n) return 0;
        if(buy){
            profit = max(-prices[ind]+ fun(ind+1,0,prices,n), 0+fun(ind+1,1, prices, n));
        }
        else{
            profit= max(prices[ind]+fun(ind+1,1,prices,n), 0+fun(ind+1,0,prices,n));
        }
        return profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return fun(0,1,prices,n);
    }
//Time Limit Exceeded 
};
//``````````````````````````````````````````````````````````
class Solution {
public:
    vector<vector<int>> memo;

    int fun(int ind, int buy, vector<int>& prices, int n )
    {
        if (ind == n) return 0;
        if (memo[ind][buy] != -1) return memo[ind][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + fun(ind + 1, 0, prices, n), fun(ind + 1, 1, prices, n));
        } else {
            profit = max(prices[ind] + fun(ind + 1, 1, prices, n), fun(ind + 1, 0, prices, n));
        }

        return memo[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo.assign(n, vector<int>(2, -1)); // Initialize memoization array
        return fun(0, 1, prices, n);
    }
    //time complexity of the memoized solution is O(n).
};
//```````````````````````````````````````````
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
                profit += (prices[i] - prices[i-1]);
        }
        return profit;
    }
};
