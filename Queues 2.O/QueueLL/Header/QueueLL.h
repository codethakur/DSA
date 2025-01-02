#pragma once
#ifndef QUEUELL_H
#define QUEUELL_H
#include <iostream>
#include <stdexcept>
#include <string>

// Queue Node
template <typename T>
struct ListNode {
    T data;
    ListNode* next;
};

// Queue Structure
template <typename T>
struct Queue {
    ListNode<T>* front;
    ListNode<T>* rear;
};

inline void warning(const std::string& message) {
    std::cerr << "Warning: " << message << "\n";
    std::cerr.flush(); // Ensure immediate output
}

// Create a queue
template <typename T>
Queue<T>* CreateQueue() {
    Queue<T>* q = new Queue<T>();
    q->front = nullptr;
    q->rear = nullptr;
    return q;
}

// Get queue size
template <typename T>
int QSize(Queue<T>* q) {
    ListNode<T>* temp = q->front;
    int count = 0;

    while (temp) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Destroy queue
template <typename T>
void DestroyQueue(Queue<T>* q) {
    while (q->front) {
        ListNode<T>* temp = q->front;
        q->front = q->front->next;
        delete temp;
    }
    delete q;
}

// Enqueue
template <typename T>
void Enqueue(Queue<T>* q, T value) {
    ListNode<T>* newNode = new ListNode<T>{ value, nullptr };
    if (q->rear) {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    if (!q->front) {
        q->front = q->rear;
    }
}

// Dequeue
template <typename T>
T Dequeue(Queue<T>* q) {
    if (!q->front) {
        throw std::underflow_error("Queue is empty");
    }

    ListNode<T>* temp = q->front;
    T value = temp->data;
    q->front = q->front->next;

    if (!q->front) {
        q->rear = nullptr;
    }

    delete temp;
    return value;
}

// Check if queue is empty
template <typename T>
bool IsEmpty(Queue<T>* q) {
    return !q->front;
}
template<typename T>
T rearElement(Queue<T>* Q) {
    if (!Q->rear) {
        throw std::underflow_error("Queue is empty. No rear element exists.");
    }
    return Q->rear->data;
}



//delete Queue
template <typename T>
void deleteQ(Queue<T>* Q) {
    if (Q == nullptr) {
        warning("Queue is null!");
        return;
    }

    ListNode<T>* temp;
    while (Q->front != nullptr) {
        temp = Q->front;
        warning("Element being deleted: " + std::to_string(temp->data)); // This will print to std::cerr

        Q->front = Q->front->next;
        delete temp;
    }

    delete Q; // Delete the queue itself
    warning("Queue successfully deleted!"); // Print queue deletion message
}


// Print queue
template <typename T>
void PrintQueues(Queue<T>* q) {
    ListNode<T>* temp = q->front;
    if (!temp) {
        std::cerr << "Queue is Empty!\n";
        return;
    }
    while (temp) {
        std::cout << temp->data;
        temp = temp->next;
        if (temp) std::cout << " --> ";
    }
    std::cout << "\n";
}

#endif
