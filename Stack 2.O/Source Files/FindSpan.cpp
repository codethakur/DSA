#include <iostream>
#include <vector>
#include "stack.h"  

// Function to calculate spans
std::vector<int> FindSpan(int A[], int n) {
    auto S = createStack<int>(n);  
    std::vector<int> SpanResult(n); // Vector to store span results

    for (int i = 0; i < n; i++) {
        // Pop elements from stack while current price is greater than or equal to top
        while (!isEmpty(S) && A[peek(S)] <= A[i]) {
            pop(S);
        }

        // If stack is empty, all previous prices are smaller
        if (isEmpty(S)) {
            SpanResult[i] = i + 1;
        }
        else {
            SpanResult[i] = i - peek(S); // Use peek(S) instead of st.top()
        }

        // Push current index to the stack
        push(S, i);
    }

    return SpanResult;
}

int main() {
    int A[] = { 100, 80, 60, 70, 60, 75, 85 };
    int n = sizeof(A) / sizeof(A[0]);

    std::vector<int> span = FindSpan(A, n);

    std::cout << "Span: ";
    for (int val : span) {
        std::cout << val << " ";
    }

    return 0;
}
