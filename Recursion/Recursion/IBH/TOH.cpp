#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char target, char auxiliary) {
    // Base case
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    // Move top n-1 disks to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, target);
    // Move nth disk to target
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    // Move n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
