#include<iostream>
#include<vector>

void solve(std::vector<int>&v, int k, int index, int &ans)
{
    if(v.size()==1){
        ans=v[0];
        std::cout<<ans;
        return;
    }
    index = (index+k)%v.size();
    v.erase(v.begin()+index);
    solve(v, k, index, ans);

    return;
}

int main()
{
    int n, k;
    std::cout<<"Enter the number of person and enter the k value: ";
    std::cin>>n>>k;

    std::vector<int>v;
    for (size_t i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    int index = 0;
    int ans = -1;
    solve(v, k-1, index, ans);

    return 0;

}