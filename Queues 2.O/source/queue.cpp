#include "queue.h"
#include <iostream>
#include <memory>

// Function definitions
template <typename T>
std::unique_ptr<Queue<T>> CreateQueue(size_t capacity) {
    auto Q = std::make_unique<Queue<T>>();
    Q->capacity = static_cast<int>(capacity);
    Q->size = 0;
    Q->front = 0;
    Q->rear = -1;
    Q->array = std::make_unique<T[]>(capacity); // Allocate array with unique_ptr
    return Q;
}

template <typename T>
size_t Size(const std::unique_ptr<Queue<T>>& Q) {
    return Q->size;
}

template <typename T>
void resizeQueue(std::unique_ptr<Queue<T>>& Q) {
    int old_capacity = Q->capacity;
    Q->capacity *= 2;  // Double the capacity
    std::unique_ptr<T[]> new_array = std::make_unique<T[]>(Q->capacity);  // New array with doubled capacity

    // Copy elements to new array
    int j = 0;
    for (int i = Q->front; i != Q->rear; i = (i + 1) % old_capacity) {
        new_array[j++] = Q->array[i];
    }

    // Copy the rear element
    new_array[j] = Q->array[Q->rear];

    // Update array and indices
    Q->array = std::move(new_array);
    Q->front = 0;  // Reset front to 0 because the new array is unwrapped
    Q->rear = j;   // Update rear index"

}


template <typename T>
T FrontElement(const std::unique_ptr<Queue<T>>& Q) {
    if (IsEmpty(Q)) {
        throw std::underflow_error("Queue is empty");
    }
    return Q->array[Q->front];
}

template <typename T>
T RearElement(const std::unique_ptr<Queue<T>>& Q) {
    if (IsEmpty(Q)) {
        throw std::underflow_error("Queue is empty");
    }
    return Q->array[Q->rear];
}

template <typename T>
bool IsEmpty(const std::unique_ptr<Queue<T>>& Q) {
    return Q->size == 0;
}

template <typename T>
bool IsFull(const std::unique_ptr<Queue<T>>& Q) {
    return Q->size == Q->capacity;
}

/*
template <typename T>
void enQueue(std::unique_ptr<Queue<T>>& Q, T value) {
    if (IsFull(Q)) {
        throw std::overflow_error("Queue is full");
    }
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = value;
    Q->size++;
}
*/

template <typename T>
void enQueue(std::unique_ptr<Queue<T>>& Q, T value) {
    if (IsFull(Q)) {
        resizeQueue(Q);
    }
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = value;
    Q->size++;
}

template <typename T>
T deQueue(std::unique_ptr<Queue<T>>& Q) {
    if (IsEmpty(Q)) {
        throw std::underflow_error("Queue is empty");
    }
    T data = Q->array[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    Q->size--;
    return data;
}

template <typename T>
void deleteQ(std::unique_ptr<Queue<T>>& Q) {
    Q.reset(); // Reset the unique_ptr, releasing memory
}

// Explicit template instantiations for type `int`
template std::unique_ptr<Queue<int>> CreateQueue<int>(size_t);
template size_t Size<int>(const std::unique_ptr<Queue<int>>&);
template int FrontElement<int>(const std::unique_ptr<Queue<int>>&);
template int RearElement<int>(const std::unique_ptr<Queue<int>>&);
template bool IsEmpty<int>(const std::unique_ptr<Queue<int>>&);
template bool IsFull<int>(const std::unique_ptr<Queue<int>>&);
template void enQueue<int>(std::unique_ptr<Queue<int>>&, int);
template int deQueue<int>(std::unique_ptr<Queue<int>>&);
template void deleteQ<int>(std::unique_ptr<Queue<int>>&);
