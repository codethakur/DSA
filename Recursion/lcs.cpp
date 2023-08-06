#include<bits/stdc++.h>
using namespace std;

int lcs(string text1, string text2, int n, int m )
{
    if(n==0 || m==0) return 0;

    if(text1[n-1] == text2[m-1])
        return  1+ lcs(text1,text2,n-1,m-1);
    else
        return max(lcs(text1,text2,n-1,m), lcs(text1, text2,n,m-1));    
}
int main()
{
    string text1;
    string text2;

    cin>>text1>>text2;

    cout<<lcs(text1,text2,text1.length(), text2.length());

    return 0;
}