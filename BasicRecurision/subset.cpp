#include<bits/stdc++.h>
using namespace std;

void solve(string input, string output, int &count)
{
    if(input.length()==0){
        cout<<output<<" ";
        count++;
        return;
    }
    string op1 = output;
    string op2 =output;

    op2.push_back(input[0]);
    input.erase(input.begin()+0);

    solve(input,op1, count);
    solve(input,op2, count);
    

}
int main()
{
    string input;
    cin>> input;
    int count = 0;
    string output=" ";
    solve(input, output,count);
    cout<<count;
    return 0;
}
