#include<bits/stdc++.h>
using namespace std;

void Ntimes(int i, int n)
{
    if(i>n){
        return;
    }
    cout<<"printing N times:"<<i<<endl;
    Ntimes(i+1,n);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Ntimes(1,n);
    return 0;
}