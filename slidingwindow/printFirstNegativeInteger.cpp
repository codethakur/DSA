#include <iostream>
#include <vector>
#include <list>

std::vector<long long> printFirstNegativeInteger(long long int A[],
                                                long long int N, long long int K) {
    int i = 0, j = 0;
    std::list<long long> listDS;
    std::vector<long long> V;

    while (j < N) {
        if (A[j] < 0) {
            listDS.push_back(A[j]);
        }

        if (j - i + 1 < K) {
            j++;
        } else if (j - i + 1 == K) {
            if (listDS.empty()) {
                V.push_back(0);
            } else {
                V.push_back(listDS.front());
                if (A[i] == listDS.front()) {
                    listDS.pop_front();
                }
            }
            i++;
            j++;
        }
    }

    return V;
}

int main() {
    long long int A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int N = sizeof(A) / sizeof(A[0]);
    long long int K = 3;

    std::vector<long long> result = printFirstNegativeInteger(A, N, K);

    for (long long num : result) {
        std::cout << num << " ";
    }

    return 0;
}
