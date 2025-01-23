#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <string_view>
#include <optional>
#include <format>

void Solve(const std::string& digits, int index, std::string& temp, 
           const std::unordered_map<char, std::string_view>& keypad_map, 
           std::vector<std::string>& result) {
    if (index == digits.size()) {
        result.push_back(temp);
        return;
    }
    char ch = digits[index];
    for (char letter : keypad_map.at(ch)) {
        temp += letter;
        Solve(digits, index + 1, temp, keypad_map, result);
        temp.pop_back();
    }
}

std::optional<std::vector<std::string>> letterCombinations(std::string& digits) {
    if (digits.empty()) return std::nullopt;

    std::unordered_map<char, std::string_view> keypad_map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    std::vector<std::string> result;
    std::string curr_str;
    Solve(digits, 0, curr_str, keypad_map, result);
    return result;
}

int main() {
    std::string digits;
    std::cin >> digits;

    auto ans = letterCombinations(digits);
    if (ans) {
        for (size_t i = 0; i < ans->size(); ++i) {
            std::cout << std::format("\"{}\"{}", (*ans)[i], (i != ans->size() - 1 ? "," : ""));
        }
    } else {
        std::cout << "No valid combinations.\n";
    }
    return 0;
}
