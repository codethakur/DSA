#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;  // 1 and negative numbers are not prime
    }

    // Loop from 2 to the square root of n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;  // If n is divisible by i, it's not a prime number
        }
    }
    return true;  // If no divisors found, n is a prime number
}
int main() {
    int n; 
    cin >> n;
    if (isPrime(n)) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }
    return 0;
}