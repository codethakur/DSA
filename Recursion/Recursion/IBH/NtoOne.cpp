#include<iostream>

void Print(int n)
{
    if(n==1){
        std::cout<<n<<" ";
        return;
    }
    std::cout<<n<<" ";
    Print(n-1);
     /*  
        Print(n-1);
        std::cout<<n<<" "; //one to N
     */
}

int main()
{
    int n = 7;
    Print(n);

    return 0;
}
