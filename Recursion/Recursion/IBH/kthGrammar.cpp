#include <iostream>
#include <cmath>

// Recursive function to find the k-th symbol in the n-th row
int kthGrammar(int n, int k) {
    // Base case
    if (n == 1 && k == 1) {
        return 0;
    }

    // Midpoint of the current row
    int mid = pow(2, n - 1) / 2;

    // Determine which half of the row k belongs to
    if (k <= mid) {
        return kthGrammar(n - 1, k); // Same as in the previous row
    } else {
        return !kthGrammar(n - 1, k - mid); // Complement of the first half
    }
}

int main() {
    // Example inputsx
    int n = 2, k = 2;

    // Output the result
    std::cout << "The " << k << "-th symbol in the " << n << "-th row is: " << kthGrammar(n, k) << std::endl;

    return 0;
}
