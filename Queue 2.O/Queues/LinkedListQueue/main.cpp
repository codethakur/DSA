#include <iostream>
#include "LinkedListQueue.h"

int main()
{
    using namespace LinkedListQueue;

    // Explicitly declare the queue as a pointer to Queue<int>
    //Queue<int>* q = createQueue<int>(); 
    auto q = createQueue<int>(); // Specify the type here

    for (int  i = 0; i <=10; i++)
    {
        enqueue(q,i);
    }


    std::cout << "Front element: " << frontElement(q) << "\n";
    std::cout << "Rear element: " << rearElement(q) << "\n";
    std::cout << "Queue size: " << QSize(q) << "\n";

    dequeue(q);
    std::cout << "Queue size after dequeue: " << QSize(q) << "\n";

    std::cout<<"\n-------------------\n";
    deleteallQElement(q);
    destroyQueue(q); // Clean up the queue
    return 0;
}