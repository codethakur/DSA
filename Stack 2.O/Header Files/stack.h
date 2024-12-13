#include <iostream>
#include <cstring>  // For std::memcpy
#include <cstdint>  // For uint64_t
#include <stdexcept>  // Include this header for std::out_of_range

template <typename T>
struct Stack {
    int top;
    int capacity;
    T* array;
};

template <typename T>
Stack<T>* createStack(int capacity) {
    Stack<T>* stack = new Stack<T>;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new T[capacity];
    return stack;
}

template <typename T>
bool isEmpty(Stack<T>* S) {
    return S->top == -1;
}

template <typename T>
bool isFull(Stack<T>* S) {
    return S->top == S->capacity - 1;
}

/*template <typename T>
void doubleStack(Stack<T>* S) {
    S->capacity *= 2;
    T* newArray = new T[S->capacity];
    for (int i = 0; i < S->top; ++i) {
        newArray[i] = S->array[i];
    }
    delete[] S->array;
    S->array = newArray;
}*/


template <typename T>
void doubleStack(Stack<T>* S) {
    // Check for potential overflow when calculating the new size
    if (S->top + 1 > SIZE_MAX / sizeof(T)) {
        std::cerr << "Overflow detected while calculating new array size!" << std::endl;
        return;
    }

    // Double the capacity
    S->capacity *= 2;

    // Calculate the new size in bytes
    size_t newSize = (S->top + 1) * sizeof(T);

    // Allocate the new array
    T* newArray = new T[S->capacity];

    // Safely copy the data using std::memcpy
    std::memcpy(newArray, S->array, newSize);

    // Clean up the old array
    delete[] S->array;

    // Update the stack with the new array
    S->array = newArray;
}


template <typename T>
void push(Stack<T>* S, T data) {
    if (isFull(S)) {
        doubleStack(S);
    }
    S->array[++S->top] = data;
}

template <typename T>
T pop(Stack<T>* S) {
    if (isEmpty(S)) {
        throw std::out_of_range("Stack underflow");
    }
    return S->array[S->top--];
}

template <typename T>
T peek(Stack<T>* S) {
    if (isEmpty(S)) {
        std::cerr << "Attempt to peek an empty stack!" << std::endl;
        throw std::out_of_range("Stack underflow");
    }
    std::cout << "Peeking: " << S->array[S->top] << std::endl;
    return S->array[S->top];
}


template <typename T>
size_t Size(Stack<T>* S) {
    return S->top + 1;
}

template <typename T>
T getMinimum(Stack<T>* minStack) {
    if (isEmpty(minStack)) {
        std::cerr << "Error: Attempted to get minimum from an empty minStack!" << std::endl;
        throw std::runtime_error("minStack is empty");
    }
    return peek(minStack);
}

template <typename T>
void deleteStack(Stack<T>* S) {
    delete[] S->array;
    delete S;
}
