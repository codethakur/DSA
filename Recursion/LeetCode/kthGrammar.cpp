#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) {
            return 0; // Base case for the first row, which always starts with 0.
        }
        int mid = (pow(2, n-1))/2; // Calculate the midpoint of the previous row.

        if(k <= mid) {
            return kthGrammar(n - 1, k); // If k is in the first half of the row, recurse on the previous row.
        } else {
            return !kthGrammar(n - 1, k - mid); // If k is in the second half, negate the value from the previous row.
        }
    }
};

int main() {
    Solution solution;
    
    // Example usage:
    int n = 4;
    int k = 5;
    int result = solution.kthGrammar(n, k);
    
    std::cout << "The value at position " << k << " in row " << n << " is: " << result << std::endl;
    
    return 0;
}
