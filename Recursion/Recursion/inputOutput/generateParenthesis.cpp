#include <iostream>
#include <string>
#include <vector>
#include <ranges> // For std::ranges::join

void solve(const std::string& output, int open, int close, std::vector<std::string>& v)
{
    if (open == 0 && close == 0) {
        v.push_back(output);
        return;
    }
    if (open > 0) {
        solve(output + std::string(1, '('), open - 1, close, v);
    }
    if (close > open) {
        solve(output + std::string(1, ')'), open, close - 1, v);
    }
}

std::vector<std::string> generateParenthesis(int n)
{
    std::vector<std::string> result;
    solve("", n, n, result); 
    return result;
}

int main()
{
    int n;
    std::cout << "Enter pairs of parentheses: ";
    std::cin >> n;

    auto pairs = generateParenthesis(n);

    std::cout << "[";
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << '"' << pairs[i] << '"';
        if (i < pairs.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}

