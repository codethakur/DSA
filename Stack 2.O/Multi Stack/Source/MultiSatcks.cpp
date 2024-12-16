#include <iostream>
#include "MultiStacks.h"

int main() {
    size_t capacity = 5;
    auto* twoStack = createMultiStack<int>(capacity);

    // Push elements alternately into Stack 1 and Stack 2
    for (int i = 0; i < capacity; i++) {
        int stackNumber = (i % 2) + 1; // Alternate between Stack 1 and Stack 2
        Push(twoStack, stackNumber, i);
        std::cout << "Pushed element " << i << " into Stack " << stackNumber << "\n";
    }

    std::cout << "-------------------------------------\n";
    std::cout << "First Stack of top element is: " << peek<int>(twoStack, 1) << std::endl;
    std::cout << "Second Stack of top element is: " << peek<int>(twoStack, 2) << std::endl;

    std::cout << "Size of First Stack is: " << size<int>(twoStack, 1) << std::endl;
    std::cout << "Size of Second Stack is: " << size<int>(twoStack, 2) << std::endl;
    std::cout << "-------------------------------------\n";
    // Pop elements alternately from Stack 1 and Stack 2
    for (int i = 0; i < capacity; i++) {
        int stackNumber = (i % 2) + 1; // Alternate between Stack 1 and Stack 2
        try {
            int poppedElement = pop<int>(twoStack, stackNumber);
            std::cout << "Popped element " << poppedElement << " from Stack " << stackNumber << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << " for Stack " << stackNumber << "\n";
        }
    }

    if (isEmpty<int>(twoStack, 1) || isEmpty<int>(twoStack, 2)) {
        std::cout << "Stack is empty!\n";
    }
    else {
        std::cout << "Stack is not empty!\n";
    }

    // Clean up the allocated memory
    
    deleteStack(twoStack);


    std::cin.get();
    return 0;
}

