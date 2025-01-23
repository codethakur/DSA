#include <iostream>
#include <string>
#include <string_view>

void Solve(std::string_view input, std::string output) {
    // Base case: when input is empty, print the current subset
    if (input.empty()) {
        std::cout << output << std::endl;
        return;
    }

    // Create two options:
    // Option 1: Include the first character with a space (if output is not empty)
    std::string op1 = output;
    if (!output.empty()) {
        op1.push_back(' '); // Add a space before the character
    }
    op1.push_back(input.front()); // Add the first character

    // Option 2: Include the first character without a space
    std::string op2 = output;
    op2.push_back(input.front());

    // Remove the first character by creating a new `std::string_view` slice
    std::string_view remaining = input.substr(1);

    // Recursive calls
    Solve(remaining, op1);
    Solve(remaining, op2);
}

int main() {
    std::string input;

    std::cout << "Enter the String: ";
    std::cin >> input;

    std::string_view input_view(input); // Create a string_view for the input
    std::string output;

    // Start with the first character in the output
    output.push_back(input_view.front());
    input_view = input_view.substr(1);

    Solve(input_view, output);

    return 0;
}
