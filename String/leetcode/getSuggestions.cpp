#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert a string to lowercase
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to get suggestions for the customer query
vector<vector<string>> getSuggestions(vector<string>& repository, string customerQuery) {
    // Convert repository strings to lowercase
    for (string& word : repository) {
        word = toLowerCase(word);
    }
    
    // Sort the repository alphabetically
    sort(repository.begin(), repository.end());
    
    vector<vector<string>> result;
    string prefix;
    
    // Process each character of the customerQuery
    for (int i = 0; i < customerQuery.length(); ++i) {
        prefix += tolower(customerQuery[i]);  // Build the prefix up to this character
        
        if (prefix.length() < 2) {
            // Skip suggestions for prefixes shorter than 2 characters
            continue;
        }
        
        vector<string> suggestions;
        
        // Find matching words from the repository that start with the current prefix
        for (const string& word : repository) {
            if (word.find(prefix) == 0) {
                suggestions.push_back(word);
            }
            if (suggestions.size() == 3) {
                break;  // We need only the top 3 suggestions
            }
        }
        
        // Add the suggestions for this prefix to the result
        result.push_back(suggestions);
    }
    
    return result;
}

// Function to print the result
void printSuggestions(const vector<vector<string>>& suggestions) {
    for (const auto& suggestionList : suggestions) {
        for (const string& suggestion : suggestionList) {
            cout << suggestion << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<string> repository = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string customerQuery = "mouse";
    
    vector<vector<string>> suggestions = getSuggestions(repository, customerQuery);
    
    printSuggestions(suggestions);
    
    return 0;
}
