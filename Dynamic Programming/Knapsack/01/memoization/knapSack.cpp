class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
     int t[1001][1001];
    
    int knapSackUtil(int W, int wt[], int val[], int n){
        if(t[n][W]!=-1){
            return t[n][W];
        }else{
            if(W==0 || n==0){
                return 0;
            }
            if(wt[n-1]>W){
                return t[n][W] = knapSackUtil(W,wt,val,n-1);
            }else{
                return t[n][W] = max(val[n-1]+knapSackUtil(W-wt[n-1],wt,val,n-1),
                                        knapSackUtil(W,wt,val,n-1));
            }
        }
    }   
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(t,-1,sizeof(t));
       return knapSackUtil(W,wt,val,n);
    }
};
