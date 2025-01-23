#ifndef ARRQUEUES_H
#define ARRQUEUES_H

#include <iostream>
#include <climits>

namespace QueueModule
{
    template <typename T>
    struct Queue
    {
        int front, rear;
        int capacity;
        int size;
        T *array;
    };

    // Function to create a queue with a given capacity
    template <typename T>
    Queue<T> *createQueue(int capacity)
    {
        Queue<T> *q = new Queue<T>();
        if (!q)
        {
            std::cerr << "Memory allocation failed for queue structure.\n";
            return nullptr;
        }

        q->capacity = capacity;
        q->size = 0;
        q->front = -1;
        q->rear = -1;
        q->array = new T[q->capacity];

        if (!q->array)
        {
            std::cerr << "Memory allocation failed for queue array.\n";
            delete q;
            return nullptr;
        }

        return q;
    }
    template <typename T>
    int size(Queue<T> *q)
    {
        if (q == nullptr)
        {
            return 0; // If the queue is destroyed (null), return size as 0.
        }
        return q->size;
    }

    template <typename T>
    T frontElement(Queue<T> *q)
    {
        return q->array[q->front];
    }

    template <typename T>
    T rearElement(Queue<T> *q)
    {
        return q->array[q->rear];
    }

    template <typename T>
    T isEmpty(Queue<T> *q)
    {
        return (q->size == 0);
    }

    template <typename T>
    T isFull(Queue<T> *q)
    {
        return (q->size == q->capacity);
    }

    // Function to adding an element
    template <typename T>
    void enQueue(Queue<T> *q, int data)
    {
        if (isFull(q))
        {
            std::cerr << "Queue overflow. Cannot enqueue " << data << ".\n";
            return;
        }

        q->rear = (q->rear + 1) % q->capacity; // Circular increment
        q->array[q->rear] = data;
        if (q->front == -1)
        { // If the queue was empty
            q->front = q->rear;
        }
        q->size++;
    }
    // Removes an element form front of the queue
    template <typename T>
    T deQueue(Queue<T> *q)
    {
        int data = INT_MIN;
        if (isEmpty(q))
        {
            std::cerr << "Queue is Empty\n";
            return data;
        }
        data = q->array[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
            q->size -= 1;
        }
        else
        {
            q->front = (q->front + 1) % q->capacity;
            q->size -= 1;
        }
        return data;
    }
    // Function to destroy the queue and free memory
    template <typename T>
    void destroyQueue(Queue<T> *q)
    {
        if (q)
        {
            delete[] q->array;
            delete q;
        }
    }
}
#endif // ARRQUEUES_H