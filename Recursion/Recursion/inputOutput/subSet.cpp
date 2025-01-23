#include <iostream>
#include <string>

void Solve(std::string input, std::string output) {
    // Base case: when the input string is empty, print the output
    if (input.length() == 0) {
        std::cout << "\"" << output << "\" ";  // Printing the current subset with quotes
        return;
    }

    // Recursive calls to explore both possibilities:
    // 1. Exclude the current character
    // 2. Include the current character
    Solve(input.substr(1), output);  // Exclude the current character
    Solve(input.substr(1), output + input[0]);  // Include the current character
}

int main() {
    std::string input;
    std::cout << "Enter the string: ";
    std::cin >> input;

    // Initially, the output is empty and the full string is available to explore
    Solve(input, "");

    return 0;
}
