#include<bits/stdc++.h>
using namespace std;

int solv(vector<int> V, int k, int index)
{
    if (V.size() == 1)
    {
        return V[0] + 1; // Add 1 because the people are numbered from 1 to n
    }
    index = (index + k) % V.size();
    V.erase(V.begin() + index);
    return solv(V, k, index);
}

int safePos(int n, int k) {
    vector<int> V;
    for (int i = 0; i < n; i++)
    {
        V.push_back(i);
    }
    k--;
    int index = 0;
    return solv(V, k, index);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int result = safePos(n, k);
    cout << result << endl;
    return 0;
}
