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
/*
    int j=-1;
for(int i=0; i<nums.size(); i++)
{
    if(nums[i]==0){
        j=i;        //Time O(x);
        break;
    }
}
for(int i=j+1; i<n; i++)
{
    if(nums[i]!=0)
    {
        swap(nums[i],nums[j]); //Time O(n-x);
        j++;
    }
}
//Time = O(x) + O(n-x) x+(-x)=> O(N) TC with no extra space;
return nums;
*/

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
