#include <bits/stdc++.h>
using namespace std;

void Solve(string input, string output, set<string>& uniqueSubsets)
{
    if (input.length() == 0) {
        // Check for empty output and add to the set if it's unique
        if (!output.empty()) {
            uniqueSubsets.insert(output);
        }
        return;
    }

    string output1 = output;
    string output2 = output;
    output2.push_back(input[0]);

    input.erase(input.begin() + 0);

    Solve(input, output1, uniqueSubsets);
    Solve(input, output2, uniqueSubsets);
}

int main()
{
    string input;
    cin >> input;
    string output;
    set<string> uniqueSubsets;

    Solve(input, output, uniqueSubsets);

    // Print unique subsets
    for (const string& subset : uniqueSubsets) {
        cout << subset << endl;
    }

    return 0;
}
