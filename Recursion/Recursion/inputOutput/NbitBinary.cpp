#include<iostream>
#include<string>

void Solve(int one, int zero, int n,  std::string &output)
{
    if(n==0){
        std::cout<<'\"'<<output<<'\"';
        if(!output.size()-2);
        {
            std::cout<<", ";
        }
        return;
    }

    std::string op1 = output;
    op1.push_back('1');
    Solve(one+1,zero, n-1, op1);

    if(one>zero){
        std::string op2 = output;
        op2.push_back('0');
        Solve(one, zero+1, n-1, op2);
    }
    return;

}

int main()
{ 
    int n;
    std::cout<<"Enter n: ";
    std::cin>>n;

    std::string output = "";
    int one=0, zero = 0;
   Solve(one,zero, n, output);

   return 0;
}