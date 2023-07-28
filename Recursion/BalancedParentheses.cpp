#include<bits/stdc++.h>
using namespace std;

void solv(int open, int close, string output, vector<string >&V)
{
    if(open==0 && close ==0)
    {
        V.push_back(output);
        return;
    }
    if(open!=0){
        string op1=output;
        op1.push_back('(');
        solv(open-1,close,op1,V);
    }if(close>open){
        string op2=output;
        op2.push_back(')');
        solv(open, close-1,op2,V);
    }
}

vector<string>fun(int n)
{
    int open =n;
    int close =n;
    string output="";
    vector<string>V;

    solv(open, close, output,V);

    return V;
}

int main()
{
    int n;
    cin>>n;
    vector<string> parentheses = fun(n);
    for (const string &p : parentheses)
    {
        cout << p << endl;
    }

    return 0;
    
}