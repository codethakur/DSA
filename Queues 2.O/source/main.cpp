#include <iostream>
#include "queue.h"
#include <memory>

int main() {
    try {
        auto Q = CreateQueue<int>(5);

        std::cout << "Enqueue elements:\n";
        for (int i = 0; i < 5; i++) {
            enQueue(Q, i);
            std::cout << "Enqueued: " << i << std::endl;
        }
        enQueue(Q, 100);

        std::cout << "-------------- Dequeue elements ------------\n";
        // Dequeue elements
        while (!IsEmpty(Q)) {
            int front = FrontElement(Q);
            std::cout << "Front Element: " << front << std::endl;
            int dequeued = deQueue(Q); // Only pass the queue
            std::cout << "Dequeued: " << dequeued << std::endl;
        }

        std::cout << "-------------- Queue is empty now ------------\n";

        // Example: Attempting to dequeue from an empty queue
        try {
            deQueue(Q);
        }
        catch (const std::exception& e) {
            std::cerr << "Error while dequeuing from an empty queue: " << e.what() << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    system("pause>0");
    return 0;
}
