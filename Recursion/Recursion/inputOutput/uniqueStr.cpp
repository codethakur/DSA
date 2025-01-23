#include <iostream>
#include <string_view>
#include <set>
#include <ranges> // C++20

// Helper function to recursively find unique subsets
void Solve(std::string_view input, std::string output, std::set<std::string> &seen) {
    if (input.empty()) {
        seen.insert(output); // Add the subset to the set
        return;
    }
    // Exclude the first character
    Solve(input.substr(1), output, seen);
    // Include the first character
    Solve(input.substr(1), output + input[0], seen);
}

// Function to print unique subsets
void PrintUnique(std::string_view str) {
    std::set<std::string> seen; // Set to store unique subsets
    std::string output = "";
    Solve(str, output, seen);

    // Use ranges to simplify the output (C++20)
    for (const auto &subset : seen) {
        std::cout << "\"" << subset << "\"" << std::endl;
    }
}

// Main function
int main() {
    std::string str = "aab";
    PrintUnique(str);
    return 0;
}
