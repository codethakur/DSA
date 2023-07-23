#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin>>x;
if(x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    long long rev = 0;
    int original = x;
    while (x != 0) {
        int rem = x % 10;
        x /= 10;
        rev = rev * 10 + rem;
    }
    if(original == rev)
    {
        cout<< "yes";
    }
    else cout<< "no";
}
