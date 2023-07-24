#include<bits/stdc++.h>
using namespace std;
int fib(int n) {
        if(n==0)return 0;
        if(n==1) return 1;  

        return fib(n-1)+fib(n-2);  
    }

    int main()
    {
        int n;
        cin>>n;
        cout<<fib(n);

        return 0;
    }
/* Leetcode->509. Fibonacci Number
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1) return 1;  

       int last = fib(n-1);
       int slast = fib(n-2);  
       return last+slast;
    }
};
*/
