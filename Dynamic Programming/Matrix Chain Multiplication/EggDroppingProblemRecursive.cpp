#include<bits/stdc++.h>
using namespace std;

int solve(int egg, int floor)
{
    if(floor==0 || floor ==1) return floor;
    if(egg==1) return floor;

    int mn = INT_MAX;

    for(int k=1; k<=floor; k++)
    {
        int tempAns = 1 + max(solve(egg-1, k-1), solve(egg,floor-k));

        mn= min(mn, tempAns);
    }
    return mn;
}
int main()
{
    int egg;
    int floor;
    cin>>egg>>floor;
    cout<<solve(egg,floor);
    return 0;
}