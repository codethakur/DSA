#include <iostream>
using namespace std;

bool isPalindrome(string &str, int left, int right) {
    // Base case
    if (left >= right) {
        return true;
    }
    // Check mismatch
    if (str[left] != str[right]) {
        return false;
    }
    // Recursive case
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << str << " is a palindrome!" << endl;
    } else {
        cout << str << " is not a palindrome!" << endl;
    }

    return 0;
}