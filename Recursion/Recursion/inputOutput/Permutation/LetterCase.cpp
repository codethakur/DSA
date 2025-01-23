#include <iostream>
#include <string>
#include <vector>
#include <cctype> // For tolower and toupper

void Solve(std::string &input, std::string output, std::vector<std::string> &v) {
    if (input.empty()) {
        v.push_back(output);
        return;
    }

    if (isalpha(input[0])) { // Check if the current character is alphabetic
        std::string op1 = output;
        std::string op2 = output;

        op1.push_back(tolower(input[0])); // Add lowercase version
        op2.push_back(toupper(input[0])); // Add uppercase version

        input.erase(input.begin()); // Remove the processed character

        Solve(input, op1, v);
        Solve(input, op2, v);

        input.insert(input.begin(), op1.back()); // Restore input after recursion
    } else {
        std::string op1 = output;
        op1.push_back(input[0]); // Add non-alphabetic character as is
        input.erase(input.begin());

        Solve(input, op1, v);

        input.insert(input.begin(), op1.back()); // Restore input after recursion
    }
}

std::vector<std::string> func(std::string &str) {
    std::string input = str;
    std::string output = "";
    std::vector<std::string> v;

    Solve(input, output, v);
    return v;
}

int main() {
    std::string input = "a1B2";
    auto V = func(input); // Call the function correctly

    for (const auto &i : V) { // Iterate over the resulting vector
        std::cout << i << " ";
    }

    return 0;
}
