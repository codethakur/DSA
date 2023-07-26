#include <iostream>

void solv(int s, int h, int d, int n, int &cnt) {
    if (n == 1) {
        // Base case: If there is only one disk, move it from source to destination directly.
        std::cout << "Move disk 1 from S pol " << s << " to D pol " << d << std::endl;
        cnt++; // Increment the count for each move.
        return;
    }

    // Move (n-1) disks from source to helper using the destination peg as a helper.
    solv(s, d, h, n - 1, cnt);
    cnt++;

    // Move the largest disk from the source peg to the destination peg.
    std::cout << "Move disk " << n << " from source " << s << " to pol " << d << std::endl;
    cnt++;

    // Move the (n-1) disks from the helper peg to the destination peg using the source peg as a helper.
    solv(h, s, d, n - 1, cnt);
}

int main() {
    int num_disks = 3; // Change this value to the number of disks you want to use.
    int cnt = 0;
    solv(1, 2, 3, num_disks, cnt);
    std::cout << "Total number of steps: " << cnt << std::endl;
    return 0;
}
