
#include<bits/stdc++.h>
using namespace std;

void NtoOne(int i, int n)
{
    if(i<1){ 
        return;
    }
    cout<<i<<" ";
    NtoOne(i-1,n);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    NtoOne(n,n);

    return 0;
}
