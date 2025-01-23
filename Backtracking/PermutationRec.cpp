//#include <bits/stdc++.h>

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<cstring>
void permute(std::string input, std::string output, std::vector<std::string>&v)
{
    if(input.empty()){
        v.push_back(output);
        return;
    }
    std::unordered_set<char>CharSet;

    for(int i=0; i<input.size(); i++)
    {
        if(CharSet.find(input[i])== CharSet.end())
        {
             CharSet.insert(input[i]); 
            std::string newInput = input.substr(0, i) + input.substr(i+1);
            std::string newOutput = output + input[i];
            permute(newInput, newOutput, v);
        }
    }
}

std::vector<std::string>findPermutation(std::string &s)
{
    std::vector<std::string>result;
    permute(s, "", result);

    return result;
}


int main()
{
    std::string str;
    std::cin>>str;
    auto newStr = findPermutation(str);
    for (size_t i = 0; i < newStr.size(); ++i)
    {
        std::cout << '\"' << newStr[i] << '\"';
        if (i != newStr.size() - 1) 
        {
            std::cout << ", ";
        }
    }
    return 0;
}
