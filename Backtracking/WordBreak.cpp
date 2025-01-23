#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include<string_view>

void solve(const std::string &s, int index, std::vector<std::string> &temp,
           const std::unordered_set<std::string> &WordSet, std::vector<std::string> &Result) {
    // Base case: If we reach the end of the string
    if (index == s.size()) {
        std::string sentence = "";
        for (const auto & i:temp) {
            sentence +=i;
            if (!temp.empty()) {
                sentence += " "; // Add space between words
            }
        }
        Result.push_back(sentence); // Add the complete sentence to Result
        return;
    }

    // Recursive case: Try all substrings starting from 'index'
    for (int i = index; i < s.size(); i++) {
        std::string word = s.substr(index, i - index + 1); // Extract substring
        if (WordSet.find(word) != WordSet.end()) {         // If the word exists in the dictionary
            temp.push_back(word);                          // Add word to current path
            solve(s, i + 1, temp, WordSet, Result);        // Recur for remaining string
            temp.pop_back();                               // Backtrack
        }
    }
}

std::vector<std::string> wordBreak(const std::string &s, const std::vector<std::string> &dict) {
    std::vector<std::string> temp;                        // Current path
    std::unordered_set<std::string> WordSet(dict.begin(), dict.end()); // Dictionary as set
    std::vector<std::string> Result;                      // Store all valid sentences
    solve(s, 0, temp, WordSet, Result);                   // Call helper function
    return Result;
}

int main() {
    std::string str = "leetcode";
    std::vector<std::string> dictionary = {"leet", "code"};

    // Call the function
    std::vector<std::string> result = wordBreak(str, dictionary);

    // Print the results
    std::cout << "Possible segmentations:\n";
    for (const auto &sentence : result) {
        std::cout << sentence << "\n";
    }

    return 0;
}

