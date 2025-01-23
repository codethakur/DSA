#include <iostream>
#include <string_view>
#include <format> // C++20

void Solve(std::string_view S, std::string_view D, std::string_view H, int n, int &count) {
    // Base Case
    if (n == 1) {
        count++;
        std::cout << std::format("Moving plate {} from {} to {}\n", n, S, D);
        return;
    }

    // Hypothesis
    Solve(S, H, D, n - 1, count);

    // Induction
    count++;
    std::cout << std::format("Moving plate {} from {} to {}\n", n, S, D);

    // Hypothesis (repeated)
    Solve(H, D, S, n - 1, count);
}

int main() {
    int Count = 0;
    int n = 3; // Number of plates

    auto [S, D, H] = std::tuple{"Source", "Destination", "Helper"}; // Structured bindings

    Solve(S, D, H, n, Count);

    std::cout << std::format("Total number of steps: {}\n", Count);

    return 0;
}
