class Solution{   
public:
    int t[102][10002];
   Solution(){ 
       memset(t,-1,sizeof (t));
   }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {  if(i==0)
                t[i][j]=0;
                if(j==0)
                t[i][j]=1;}}
                for(int i=1;i<n+1;i++)
                {
                    for(int j=1;j<sum+1;j++)
                    {
                 if(arr[i-1]<=j)
                 t[i][j]=(t[i-1][j-arr[i-1]])||(t[i-1][j]);
                 else 
                 t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
    }
};
