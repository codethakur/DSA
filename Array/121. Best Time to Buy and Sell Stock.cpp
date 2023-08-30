class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int n = prices.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int profit = prices[j] - prices[i];
                maxP = max(maxP, profit);
            }
        }
                    //O(n^2)
        return maxP;
    }
};
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=1; //l = buy, r= sell
        int maxP=0;
        while(r<prices.size())
        {
            if(prices[l]<prices[r]){
                int profit = prices[r]-prices[l];
                maxP = max(maxP,profit);
            }else{
                l=r;
            }
            r++;

        }
        return maxP;    //Time Complexity: O(n)
                        //Space Complexity: O(1)
    }
};
*/
