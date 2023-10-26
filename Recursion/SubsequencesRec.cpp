#include <bits/stdc++.h>
using namespace std;

void Solve(string input, string output)
{
    if (input.length() == 0) {
        cout << output << endl;
        return;
    }
    /*if (input.length() == 0) {
        // Check for empty output and print a space
        if (output.empty()) {
            cout << " " << endl;
        } else {
            cout << output << endl;
        }
        return;
    }*/

    string output1 = output;
    string output2 = output;
    output2.push_back(input[0]);

    input.erase(input.begin() + 0);

    Solve(input, output1);
    Solve(input, output2);
}

int main()
{
    string input;
    cin >> input;
    string output;

    Solve(input, output);

    return 0;
}
