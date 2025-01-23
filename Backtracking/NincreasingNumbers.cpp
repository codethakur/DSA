#include<iostream>
#include<vector>

static void Solve(int n, std::vector<int>& v, std::vector<int>& res) {
    if (n == 0) {
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            ans = ans * 10 + v[i];
        }
        res.push_back(ans);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (v.empty() || i > v.back()) {  // Ensure strictly increasing
            v.push_back(i);
            Solve(n - 1, v, res);  // Decrement n to track remaining digits
            v.pop_back();  // Backtrack
        }
    }
}

std::vector<int> increasingNumbers(int n) {
    std::vector<int> v;
    std::vector<int> result;

    // Special case for n == 1 (single-digit numbers 0-9)
    if (n == 1) {
        for (int i = 0; i <= 9; i++) {
            result.push_back(i);
        }
        return result;
    }

    Solve(n, v, result);
    return result;
}

int main() {
    int n = 2;  // Example for 2-digit increasing numbers
    auto res = increasingNumbers(n);

    for (const auto num : res) {
        std::cout << num << " ";
    }
    return 0;
}
