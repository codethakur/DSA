#include<bits/stdc++.h>
using namespace std;

int fn(int n)
{
    if (n == 0) {
        return 0;
    }
    return n + fn(n - 1); // Fix the recursive call by using n - 1.
}

int main()
{
    int n = 3;
    int result = fn(n);
    cout << "Sum of integers from 1 to " << n << ": " << result << endl;
    return 0;
}
