#include<iostream>
#include<string>
#include<algorithm>

void reverse(std::string &str, int left, int rigth)
{
    if(left>=rigth){
        return;
    }
    std::swap(str[left], str[rigth]);

    reverse(str, left+1, rigth-1);

}

int main()
{
    std::string str;
    std::cout<<"Enter the  string: ";
    std::cin>>str;
    reverse(str, 0, str.length()-1);

    std::cout<<"Reverse string: "<<str;

    system("pause>0");
    return 0;
}