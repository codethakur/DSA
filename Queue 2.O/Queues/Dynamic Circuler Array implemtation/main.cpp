#include <iostream>
#include "DynamicCirArrImp.h"

int main() {
    using namespace DynamicQueueModule;

    // Create a queue with an initial capacity of 5
    Queue<int>* q = createQueue<int>(5);

    if (!q) {
        std::cerr << "Failed to create the queue.\n";
        return 1;
    }

    try {
        // Enqueue some elements
        std::cout << "Enqueuing elements: ";
        for (int i = 1; i <= 7; ++i) {
            enQueue(q, i);
            std::cout << i << " ";
        }
        std::cout << "\n";

        // Display the front and rear elements
        std::cout << "Front element: " << frontElement(q) << "\n";
        std::cout << "Rear element: " << rearElement(q) << "\n";

        // Dequeue two elements
        std::cout << "Dequeuing elements: ";
        for (int i = 0; i < 2; ++i) {
            std::cout << deQueue(q) << " ";
        }
        std::cout << "\n";

        // Enqueue more elements to check circular behavior
        std::cout << "Enqueuing elements: ";
        for (int i = 8; i <= 10; ++i) {
            enQueue(q, i);
            std::cout << i << " ";
        }
        std::cout << "\n";

        // Display the queue size
        std::cout << "Queue size: " << size(q) << "\n";

        // Display the front and rear elements again
        std::cout << "Front element: " << frontElement(q) << "\n";
        std::cout << "Rear element: " << rearElement(q) << "\n";

        // Clean up
        destroyQueue(q);
        std::cout << "Queue destroyed successfully.\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        destroyQueue(q);
        return 1;
    }

    return 0;
}
