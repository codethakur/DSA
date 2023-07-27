//PermutationWithSpaces
#include<bits/stdc++.h>
using namespace std;

void solve(string input, string output)
{
    if(input.length()==0){
        cout<<output<<" ";
        return;
    }
    string op1 = output;
    string op2 = output;

    op1.push_back(' '); // Append a single space character ' ' to op1
    op1.push_back(input[0]); // Append the next character from input to op1
    input.erase(input.begin()+0);

    solve(input,op1);
    solve(input,op2);
    return;

}
int main()
{
    string input;
    cin>>input;
    string output=" ";
    output.push_back(input[0]);
    input.erase(input.begin()+0);
    solve(input,output);

    return 0;

}