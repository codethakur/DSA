class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        
        int count = 0;
        int sum = 0;
        for(int i=0; i<N; i++)
        {
            if(sum +  arr[i]<=K){
                sum = sum+arr[i];
                count++;
            }
        }
        return count;
    }
};
