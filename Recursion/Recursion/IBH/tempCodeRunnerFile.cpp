#include <iostream>
#include<string>
void Solve(std::string  S, std::string  D, std::string  H, int n, int &count) {
    // Base Case
    if (n == 1) {
        count++;
        std::cout << "Moving plate " << n << " from " << S << " to " << D << std::endl;
        return;
    }

    // Hypothesis
    Solve(S, H, D, n - 1, count); // Assume this moves n-1 plates from S to H using D.
    count++;
    // Induction
    std::cout << "Moving plate " << n << " from " << S << " to " << D << std::endl;

    // Hypothesis (repeated)
    Solve(H, D, S, n - 1, count); // Assume this moves n-1 plates from H to D using S.

}


int main() {
    int Count=0;
    int n = 3; // Number of plates
    std::string S  = "Source"; // Source
    std::string D  = "Destination"; // Destination
   std::string  H = "Helper"; // Helper

    Solve(S, D, H, n, Count);

    std::cout<<"total number: "<< Count;

    return 0;
}
