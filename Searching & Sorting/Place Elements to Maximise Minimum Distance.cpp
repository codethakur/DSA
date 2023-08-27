#include<bits/stdc++.h>
using namespace std;

bool isfeasible(int mid, vector<int>& arr, int n, int k) {
    int pos = arr[0];
    int elements = 1;
    for (int i = 1; i < n; i++) {  // Start from index 1
        if (arr[i] - pos >= mid) {
            pos = arr[i];
            elements++;
            if (elements == k) {
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(vector<int>& arr, int n, int k) {
    sort(arr.begin(), arr.end());

    int left = 1, right = arr[n - 1] - arr[0];  // Adjust right boundary
    int result = -1;

    while (left <= right) {  // Changed the condition to include equality
        int mid = left + (right - left) / 2;  // Used a safer way to calculate mid
        if (isfeasible(mid, arr, n, k)) {
            result = max(result, mid);
            left = mid + 1;
        } else {
            right = mid - 1;  // Adjusted the right boundary
        }
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << largestMinDistance(arr, n, k) << endl;
    return 0;
}
