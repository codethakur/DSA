
#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
void Solve(std::string &str, int start, std::vector<std::string>&v)
{
    if (start == str.size()) {
    v.push_back(str);
    return;
}
    std::unordered_set<char>CharSet;
    for(int i =start; i<str.size(); i++)
    {
        if(CharSet.find(str[i])==CharSet.end())
        {
            CharSet.insert(str[i]);
            std::swap(str[start], str[i]);
            Solve(str, start+1,v);
            std::swap(str[start], str[i]);
        }
    }
}

std::vector<std::string>findPermutation(std::string &s)
{
    std::vector<std::string>result;
    Solve(s, 0, result);

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


