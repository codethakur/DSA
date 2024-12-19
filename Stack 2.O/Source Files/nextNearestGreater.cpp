#include <iostream>
#include <vector>
#include <climits>
#include "stack.h"

void nextNearestGreater(const std::vector<int>& arr) {
    int n = arr.size();
    auto st = createStack<int>(n);

    // Iterate over each element in the array
    for (int i = 0; i < n; i++) {
        int current = arr[i];

        // Find the nearest greater element for the previous elements in the stack
        while (!isEmpty(st) && peek(st) < current) {
            int element = pop(st);
            std::cout << "For the element " << element << ", the nearest greater element is " << current << ".\n";
        }

        // Push the current element onto the stack
        push(st, arr[i]);
    }

    // For remaining elements in the stack, there is no greater element
    while (!isEmpty(st)) {
        int element = pop(st);
        std::cout << "For the element " << element << ", the nearest greater element is -1.\n";
    }

    // Free the memory used by the stack
    deleteStack(st);
}

int main() {
    std::vector<int> arr = { 4, 5, 2, 25 };
    nextNearestGreater(arr);
    return 0;
}
