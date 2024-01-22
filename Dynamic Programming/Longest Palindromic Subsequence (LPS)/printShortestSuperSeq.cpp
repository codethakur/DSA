#include<iostream>
#include<algorithm>
using namespace std;

string LCS(int n, int m, string str1, string str2)
{
    // Dynamic memory allocation
    int** table = new int* [n + 1];
    for (int i = 0; i <= n; ++i) {
        table[i] = new int[m + 1];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1])
                table[i][j] = 1 + table[i - 1][j - 1];
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    string result;

    // Start from the bottom right corner and one by one
    // push characters in output string
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            result.push_back(str1[i - 1]);
            i--, j--;
        }
        else if (table[i - 1][j] > table[i][j - 1])
        {
            result.push_back(str1[i - 1]);
            i--;
        }
        else
        {
            result.push_back(str2[j - 1]);
            j--;
        }
    }

    while (i > 0)
    {
        result.push_back(str1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        result.push_back(str2[j - 1]);
        j--;
    }

    // reverse the string and return it
    reverse(result.begin(), result.end());

    // Free the allocated memory
    for (int i = 0; i <= n; ++i) {
        delete[] table[i];
    }
    delete[] table;

    return result;
}

int main()
{
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    string supersequence = LCS(str1.length(), str2.length(), str1, str2);

    cout << "Shortest Supersequence: " << supersequence << endl;

   system("pause>0");
}
