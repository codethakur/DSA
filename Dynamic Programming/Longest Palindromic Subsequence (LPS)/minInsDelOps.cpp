//Minimum Number of Insertion and Deletion to convert String a to String b

#include<iostream>
using namespace std;

int LCS(int n, int m, string str1, string str2)
{
    // Dynamic memory allocation
    int** table = new int* [n + 1];
    for (int i = 0; i <= n; ++i) {
        table[i] = new int[m + 1];
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (str1[i - 1] == str2[j - 1])
                table[i][j] = 1 + table[i - 1][j - 1];
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    int  result= table[n][m];

    // Free the allocated memory
    for (int i = 0; i <= n; ++i) {
        delete[] table[i];
    }
    delete[] table;

    return result;
}

int miniOperatio(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();

    int length = LCS(n, m, str1, str2);

    int minOperations = n + m - 2 * length;

    return minOperations;
}

int main()
{
    string str1, str2;

    cin >> str1 >> str2;

    cout << miniOperatio(str1, str2) << endl;

    system("pause>0");
}
