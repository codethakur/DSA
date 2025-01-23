#include<string>
#include<vector>
#include<iostream>

bool isPaldrome(const std::string &S, int start, int end)
{
    while(start<end)
    {
        if (S[start]!=S[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}


void solve(const std::string&s, int index, std::vector<std::string>& current, std::vector<std::vector<std::string>>&result)
{
    if(index == s.size())
    {
        result.push_back(current);
        return;
    }
    for(int i = index; i<s.size(); i++)
    {
        if(isPaldrome(s, index, i)){
            current.push_back(s.substr(index, i - index + 1));
            solve(s, i+1, current, result);
            current.pop_back();
        }
    }
}

std::vector<std::vector<std::string>>partition(std::string &s)
{
    std::vector<std::vector<std::string>>result;
    std::vector<std::string>current;
    solve(s, 0, current,result);
    return result;
}

int main() {
    std::string s = "";
    std::cin>>s;
    auto partitions = partition(s);

    // Print the result
   // std::cout << "Palindrome Partitions:\n";
    for (const auto& partition : partitions) {
        std::cout << "[ ";
        for (size_t i = 0; i < partition.size(); ++i) {
           std:: cout << "\"" << partition[i] << "\"";
            if (i != partition.size() - 1) {
               std::cout << ", ";
            }
        }
        std::cout << " ]\n";
    }

    return 0;
}