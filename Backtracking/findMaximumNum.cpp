#include <iostream>
#include <string>
#include <algorithm>

    void Solve(std::string &s, int k, std::string &res, int start = 0)
    {
        if(k == 0 || start == s.size() - 1) return;
        //if(start == s.size() - 1) return;

        // Find the maximum number after the current index
        char maxNumber = *std::max_element(s.begin() + start + 1, s.end());

        for(int i = start + 1; i < s.size(); i++)
        {
            if(s[start] < s[i] && s[i] == maxNumber)
            {
                std::swap(s[start], s[i]);
                if(s.compare(res) > 0)
                {
                    res = s;
                }
                Solve(s, k - 1, res, start + 1);
                std::swap(s[start], s[i]);
            }
        }
        Solve(s, k, res, start + 1);  // Ensure to progress through the string
    }

std::string findMaximumNum(std::string &s, int k)
{
    std::string result = s;
    Solve(s, k, result, 0);
    return result;
}

int main()
{
    std::string s = "1234567";
    int k = 4;
    auto str = findMaximumNum(s, k);

    for(const auto &num : str)
    {
        std::cout << num;
    }

    return 0;
}
