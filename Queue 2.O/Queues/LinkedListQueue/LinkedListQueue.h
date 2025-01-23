#ifndef LINKEDLISTQUEUE
#define LINKEDLISTQUEUE

#include <iostream>
#include <memory>

namespace LinkedListQueue
{
    template <typename T>
    struct ListNode
    {
        T data;
        std::shared_ptr<ListNode<T>> next;
    };

    template <typename T>
    struct Queue
    {
        std::shared_ptr<ListNode<T>> front = nullptr;
        std::shared_ptr<ListNode<T>> rear = nullptr;
    };

    // Function to create a new queue
    template <typename T>
    Queue<T> *createQueue()
    {
        return new Queue<T>();
    }

    // Function to get the size of the queue
    template <typename T>
    int QSize(Queue<T> *q)
    {
        int count = 0;
        std::shared_ptr<ListNode<T>> temp = q->front;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Function to enqueue an element
    template <typename T>
    void enqueue(Queue<T> *q, T data)
    {
        auto temp = std::make_shared<ListNode<T>>();
        temp->data = data;
        temp->next = nullptr;

        if (q->rear == nullptr)
        {
            q->front = q->rear = temp;
        }
        else
        {
            q->rear->next = temp;
            q->rear = temp;
        }
    }

    // Function to check if the queue is empty
    template <typename T>
    bool isEmpty(Queue<T> *q)
    {
        return q->front == nullptr;
    }

    // Function to dequeue an element
    template <typename T>
    void dequeue(Queue<T> *q)
    {
        if (q->front == nullptr)
        {
            std::cout << "Queue is empty!\n";
            return;
        }
        std::shared_ptr<ListNode<T>> temp = q->front;
        q->front = q->front->next;
        if (q->front == nullptr)
        {
            q->rear = nullptr;
        }
        std::cout << "Removed data from queue: " << temp->data << "\n";
    }

    // Function to get the front element
    template <typename T>
    T frontElement(Queue<T> *q)
    {
        if (q->front != nullptr)
            return q->front->data;
        throw std::runtime_error("Queue is empty");
    }

    // Function to get the rear element
    template <typename T>
    T rearElement(Queue<T> *q)
    {
        if (q->rear != nullptr)
            return q->rear->data;
        throw std::runtime_error("Queue is empty");
    }
    // Function to destroy the queue
    template <typename T>
    void deleteallQElement(Queue<T> *q)
    {
        while (q->front != nullptr)
        {
            std::shared_ptr<ListNode<T>> temp = q->front;                 // Store the current front
            std::cerr << "Element being deleted: " << temp->data << "\n"; // Print the data being deleted
            q->front = q->front->next;                                    // Move front to the next element
        }
        q->rear = nullptr; 
    }
    // Function to destroy the queue
   template <typename T>
void destroyQueue(Queue<T> *q)
{
    // Set front and rear to nullptr to clear the queue
    q->front = nullptr;
    q->rear = nullptr;

    // Delete the queue structure itself
    delete q;
}

} // namespace LinkedListQueue

#endif // LINKEDLISTQUEUE