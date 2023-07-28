#include<bits/stdc++.h>
using namespace std;

void solv(int one, int zero, int n, string output)
{
    if(n==0)
    {
        cout<<output<<" ";
        return;
    }
    string op1 = output;
    op1.push_back('1');
    solv(one+1, zero, n-1, op1);

    if(one>zero)
    {
        string op2 = output;
        op2.push_back('0');
        solv(one, zero+1, n-1, op2);
    }
    return;
}
int main()
{
    int n; 
    cin>>n; 
    string output="";
    int one =0;
    int zero = 0;

    solv(one, zero, n, output);
}