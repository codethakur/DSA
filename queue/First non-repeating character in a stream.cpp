#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string A) {
        string ans;
        int count[26] = {0};  // Initialize the count array with zeros
        queue<char> q;

        for (char c : A) {
            count[c - 'a']++;  // Increment the count of the current character
            q.push(c);  // Push the current character to the queue

            while (!q.empty() && count[q.front() - 'a'] > 1) {
                q.pop();  // Pop characters with count > 1 from the front of the queue
            }

            if (q.empty()) {
                ans += '#';  // If the queue is empty, there is no non-repeating character, so append '#'
            } else {
                ans += q.front();  // Append the first non-repeating character
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string A = "aabc";
    string result = solution.FirstNonRepeating(A);

    cout << "Output: " << result << endl;

    return 0;
}
