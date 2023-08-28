lass Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int prev2 = 0;
        int prev1 = arr[0];
        for(int i=1; i<n; i++)
        {
            int incl = prev2+ arr[i];
            int  excl = prev1 + 0;
    
            int ans = max(incl, excl);
            prev2 = prev1;
            prev1 =ans;
        }
        return prev1;
    }
};
