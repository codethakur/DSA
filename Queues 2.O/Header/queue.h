#pragma once
#include <cstddef>   // For size_t
#include <memory>    // For std::unique_ptr
#include <stdexcept> // For exceptions

// Define the Queue structure
template <typename T>
struct Queue {
    int front, rear, size, capacity;
    std::unique_ptr<T[]> array; // Smart pointer for dynamic array
};

// Function declarations
template <typename T>
std::unique_ptr<Queue<T>> CreateQueue(size_t capacity);

template <typename T>
size_t Size(const std::unique_ptr<Queue<T>>& Q);

template<typename T>
void resizeQueue(const std::unique_ptr<Queue<T>>& Q);

template <typename T>
T FrontElement(const std::unique_ptr<Queue<T>>& Q);

template <typename T>
T RearElement(const std::unique_ptr<Queue<T>>& Q);

template <typename T>
bool IsEmpty(const std::unique_ptr<Queue<T>>& Q);

template <typename T>
bool IsFull(const std::unique_ptr<Queue<T>>& Q);

template <typename T>
void enQueue(std::unique_ptr<Queue<T>>& Q, T value);

template <typename T>
T deQueue(std::unique_ptr<Queue<T>>& Q);

template <typename T>
void deleteQ(std::unique_ptr<Queue<T>>& Q);
