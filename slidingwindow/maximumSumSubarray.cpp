#include<bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i = 0, j = 0;
        //int NumsSize = nums.size();
        long long sum = 0;
        long long MX = INT_MIN;
        while (j < N) {
            sum = sum + Arr[j];
            if (j - i + 1 < K) {
                j++;
            } else if (j - i + 1 == K) {
                MX = max(MX, sum);
                sum = sum - Arr[i];
                i++;
                j++;
            } else if (j - i + 1 > K) {
                sum = sum - Arr[i];
                i++;
                j++;
            }
        }
        return MX;
}       
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        cout <<maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
