#include<bits/stdc++.h>
using namespace std;

void OnetoN(int i, int n)
{
    if(i<1){ 
        return;
    }
    NtoOne(i-1,n);
    cout<<i<<" ";
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    NtoOne(n,n);

    return 0;
}
