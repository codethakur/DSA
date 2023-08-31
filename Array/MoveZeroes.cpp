#include<bits/stdc++.h>
using namespace std; 
vector<int>MoveZeroes(int n, vector<int>&nums)
{
    vector<int> temp;
    for(int i=0; i<n; i++)
    {
        if(nums[i]!=0){
            temp.push_back(nums[i]);
        }
    }
    int nz=temp.size();
    for(int i=0; i<nz; i++)
    {
        nums[i] = temp[i];
    }
    for(int i=nz; i<n; i++)
    {
        nums[i] = 0;
    }
    return nums;
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }
    vector<int>result = MoveZeroes(n, nums);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}