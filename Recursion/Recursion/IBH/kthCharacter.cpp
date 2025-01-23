#include <iostream>
#include <vector>
#include <string>

char Character(long long k, std::vector<int>& operations, int index, std::string& word) {
    if (k == 1) return 'a'; // Base case: If k = 1, return 'a'.

    if (index >= operations.size()) {
        return word[k - 1]; // If all operations are processed, return the k-th character (1-based index).
    }

    // Perform the current operation
    if (operations[index] == 0) {
        // Operation 0: Append a copy of the string to itself
        word += word;
    } else if (operations[index] == 1) {
        // Operation 1: Generate next characters and append
        std::string next = word;
        for (char& ch : next) {
            ch = (ch == 'z') ? 'a' : ch + 1; // Increment character, wrapping around at 'z'.
        }
        word += next;
    }

    // Recursively process the next operation
    return Character(k, operations, index + 1, word);
}

char kthCharacter(long long k, std::vector<int>& operations) {
    std::string word = "a";
    return Character(k, operations, 0, word);
}

int main() {
    long long k = 10;
    std::vector<int> operations = {0, 1, 0, 1};

    std::cout << kthCharacter(k, operations) << std::endl; // Output: b
    return 0;
}
