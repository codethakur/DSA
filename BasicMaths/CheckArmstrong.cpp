#include<bits/stdc++.h>
using namespace std;

bool checkArmstrong(int n) {
    int N = n;
    int digit = 0;
    int sum = 0;
    int numDigits = 0;

    // Count the number of digits in 'n'
    while (n != 0) {
        n = n / 10;
        numDigits++;
    }

    n = N; // Reset 'n' to its original value

    // Calculate the sum of digits each raised to the power of 'numDigits'
    while (n != 0) {
        digit = n % 10;
        sum += pow(digit, numDigits);
        n = n / 10;
    }

    return N == sum;
}

int main() {
    int num;
    std::cin >> num;

    if (checkArmstrong(num)) {
        cout<<"true";
    } else {
        cout<<"false";
    }

    return 0;
}
