class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        if(k==0 || k==1)
            return k;
        if(n==1)
            return k;
        int mn = INT_MAX;
        for(int i=1; i<=k; i++)
        {
            int tempAns = max(eggDrop(n-1, i-1), eggDrop(n, k-i));
            mn = min(mn,tempAns);
        }
        return mn;
    }
};
