#include <bits/stdc++.h>
using namespace std;
int calcGCD(int n, int m){
    
    if(n==m) return n;
    if(n==0) return m;
    if(m==0) return n;

    int minNum = min(n,m);
    for(int i=minNum; i>=1; i--)
        {
            if( minNum%n==0 && minNum%m==0 ){
            return i;
        }
        return 1;
    }

    
    // if(n>m){
    //     return calcGCD(n-m,m);
    // }else return calcGCD(m-n,n);

    // if(n > m) {
    //         swap(n, m);
    //     }
    //     int rem = m % n;
    //     if(rem == 0) return n;
    //     calcGCD(rem, n);
}    
int main()
{
    int n, m;
    cin>>n>>m;
    cout << "GCD of " << n << " and " << m << " is "<< calcGCD(n, m);
    return 0;
}