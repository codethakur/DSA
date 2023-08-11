#include<bits/stdc++.h>
using namespace std;


int solve(string s,int i,int j,bool istrue){
if(i>j) return 0;
if(i==j){
    if(istrue==true) return s[i]=='t';
    else return s[i]=='f';
}
int ans=0;
for(int k=i+1;k<j;k+=2){
    int lt=solve(s,i,k-1,true);
    int lf=solve(s,i,k-1,false);
    int rt=solve(s,k+1,j,true);
    int rf=solve(s,k+1,j,false);
    if(s[k]=='&'){
        if(istrue==true) ans=ans+lt*rt;
        else ans=ans+lf*rf+lf*rt+lt*rf;
    }else if(s[k]=='|'){
            if(istrue==true) ans+=(lt*rt)+(lt*rf)+(lf*rt);
            else ans+=(lf*rf);
    }else if(s[k]=='^'){
            if(istrue==true) ans+=lt*rf+rt*lf;
            else ans+=lt*rt+lf*rf;
    }
    
}
return ans;
}

int main()
{
    string s="t^f&t";
    int i=0,j=s.length()-1;
    cout<<solve(s,i,j,true);
    return 0;
}

/*Example:
Input:  symbol[]    = {T, F, T}
        operator[]  = {^, &}
Output: 2*/