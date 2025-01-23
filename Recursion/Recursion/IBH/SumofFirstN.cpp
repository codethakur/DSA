//Sum of First N Natural Numbers

#include<iostream>
int Sum(int n)
{
    //Base Case
    if(n==0 ){
        return 0;
    }
     // Recursive case (Induction)
    return n + Sum(n - 1);
}

int main()
{
    int n=10;
    std::cout<<"Sum of First "<<n<<" numsber is: "<<Sum(n);

    system("pause>0");



    
    return 0;
}