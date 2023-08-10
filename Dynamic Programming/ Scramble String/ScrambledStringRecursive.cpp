#include<bits/stdc++.h>
using namespace std;

bool Solve(string a, string b) {
    if(a.compare(b) == 0) return true;
    if(a.length() <= 0) return false;

    int n = a.length();
    bool flag = false;

    for(int i = 1; i < n; i++) {
        bool case1 = (Solve(a.substr(0, i), b.substr(n - i, i)) && Solve(a.substr(i, n - i), b.substr(0, n - i)));
        bool case2 = (Solve(a.substr(0, i), b.substr(0, i)) && Solve(a.substr(i, n - i), b.substr(i, n - i)));

        if(case1 || case2) {
            flag = true;
            break;
        }
    }

    return flag;
}

int main() {
    string a, b;
    cin >> a >> b;

    if(a.length() != b.length()) {
        cout << "Not Scrambled" << endl;
    } else {
        if(a.empty() && b.empty()) {
            cout << "Scrambled" << endl;
        } else {
            if(Solve(a, b)) {
                cout << "Scrambled" << endl;
            } else {
                cout << "Not Scrambled" << endl;
            }
        }
    }

    return 0;
}
