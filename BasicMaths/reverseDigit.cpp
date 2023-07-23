#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N = 123;
    int digit=0;
    int reverse=0;

    while(N!=0)
    {
        digit = N%10;
        reverse = reverse*10+digit;
        N = N/10;
    }
    cout<<"reverse: "<<reverse;
    return 0;
}