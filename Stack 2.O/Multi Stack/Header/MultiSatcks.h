#pragma once
#include<iostream>

template <typename T>
struct MultiSatcks
{
	int top1, top2;
	int capacity;
	T *array;
};
template <typename T>
MultiSatcks<T>* createMultiStack(size_t capacity) {
    MultiSatcks<T>* twoStack = new MultiSatcks<T>;
    if (!twoStack)
        return nullptr;

    twoStack->capacity = capacity;
    twoStack->top1 = -1;
    twoStack->top2 = capacity;
    twoStack->array = new T[capacity];
    return twoStack;
}

template<typename T>
int isEmpty(MultiSatcks<T>* twoStack, int stackNumsber) {
    if (stackNumsber == 1) {
        return (twoStack->top1 == -1);
    }
    else {
        return (twoStack->top2 == twoStack->capacity);
    }
}


template <typename T>
size_t size(MultiSatcks<T>* twoStack, int stackNumber)
{
    if (stackNumber == 1) {
        return (twoStack->top1 + 1);
    }
    else {
        return (twoStack->capacity - twoStack->top2);
    }
}

template <typename T>
bool isFull(MultiSatcks<T>* twoStack)
{
    return (size(twoStack, 1) + size(twoStack, 2) == twoStack->capacity);
}



template<typename T>
void Push(MultiSatcks<T>* twoStack, int StackNumber, T data)
{
    if (isFull(twoStack)) {  // Check if both stacks are full
        std::cerr << "Stack Overflow\n";
        return;
    }
    if (StackNumber == 1) { // Push onto stack 1
        twoStack->array[++twoStack->top1] = data;
    }
    else if (StackNumber == 2) { // Push onto stack 2
        twoStack->array[--twoStack->top2] = data;
    }
    else {
        std::cerr << "Invalid Stack Number\n";
    }
}

template <typename T>
T pop(MultiSatcks<T>* twoStack, int stackNumber)
{
    if (isEmpty(twoStack, stackNumber)) {
        throw std::out_of_range("Stack underflow");
    }
    if (stackNumber == 1) {
        return  twoStack->array[twoStack->top1--];
    }
    else {
        return twoStack->array[twoStack->top2++];
    }
}

template<typename T>
T peek(MultiSatcks<T>* twoStack, int stackNumber) {
    if (stackNumber == 1) {
        return twoStack->array[twoStack->top1];
    }
    else
        return twoStack->array[twoStack->top2];
}
template<typename T>
void deleteStack(MultiSatcks<T>* twoStack)
{
    delete[] twoStack->array;
    delete twoStack;
}
