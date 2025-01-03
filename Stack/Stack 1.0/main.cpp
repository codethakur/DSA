#include <iostream>
#include <algorithm>  // Required for std::clamp
#include <climits>
#include <cstring>  // For memcpy

struct Stack {
    int top;
    int capacity;
    int* array;
};

[[nodiscard]] struct Stack* createStack(int capacity) {
    Stack* S = new Stack;
    S->array = new int[capacity];
    S->capacity = capacity;
    S->top = -1;

    if (!S->array)
        return nullptr;

    return S;
}

int isEmpty(struct Stack* S) {
    return (S->top == -1);
}

int Size(struct Stack* S) {
    return (S->top + 1);
}

int isFull(struct Stack* S) {
    return (S->top == S->capacity - 1);
}




void doubleStack(struct Stack* S) {
    // Double the capacity
    S->capacity *= 2;

    // Create a new array with the new capacity
    int* newArray = new int[S->capacity];

    //S->array = realloc(S->array, S->capacity * sizeof(int));

    // Copy the existing elements using memcpy (faster than looping)
    std::memcpy(newArray, S->array, (S->top + 1) * sizeof(int));

    // Delete the old array
    delete[] S->array;

    // Update the stack's array pointer to the new array
    S->array = newArray;
}


void Push(struct Stack* S, int data) {
    if (isFull(S)) {
        std::cerr << "Stack Overflow\n";
    }
    else {
        // Use std::clamp to ensure 'top' doesn't go out of bounds
       // S->top = std::clamp(S->top + 1, 0, S->capacity - 1);
        S->top++;
        S->array[S->top] = data;
    }
}

void PushIntoDoubleStack(struct Stack* S, int data)
{
    if (isFull(S)) {
        doubleStack(S);
    }
    S->array[++S->top] = data;
}

int Pop(struct Stack* S) {
    if (isEmpty(S)) {
        std::cerr << "Stack is Empty\n";
        return INT_MIN;
    }
    else {
        return S->array[S->top--];
    }
}

int Peek(struct Stack* S) {
    if (isEmpty(S)) {
        std::cerr << "Stack is Empty\n";
        return INT_MIN;
    }
    else {
        return S->array[S->top];
    }
}

void deleteStack(struct Stack* S) {
    if (S) {
        delete[] S->array;  // Free the memory for the array
        delete S;  // Free the memory for the stack structure itself
    }
}

int main() {
    int capacity = 5;
    struct Stack* stk = createStack(capacity);

    if (!stk) {
        std::cerr << "Failed to create stack\n";
        return 1;
    }

    for (int i = 0; i <= 2 * capacity; i++) {
        PushIntoDoubleStack(stk, i);

    }

    std::cout << "Top Element: " << Peek(stk) << std::endl;
    std::cout << "Stack Size: " << Size(stk) << std::endl;

    // Pop all elements
    for (int i = 0; i <= capacity; i++) {
        std::cout << "Popped Elements:" << Pop(stk) << std::endl;
    }
    std::cout << std::endl;

    if (isEmpty(stk)) {
        std::cout << "Stack is Empty\n";
    }
    else {
        std::cout << "Stack is not Empty\n";
    }

    deleteStack(stk);

    system("pause>0");
    return 0;
}
