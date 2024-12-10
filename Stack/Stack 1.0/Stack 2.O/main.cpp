#include <iostream>
#include <vector>

struct Stack {
    int top;
    std::vector<int> array; // Using std::vector instead of raw array
};

[[nodiscard]] struct Stack* createStack(int capacity) {
    Stack* S = new Stack;
    S->array.resize(capacity); // Resize the vector to the given capacity
    S->top = -1;
    return S;
}

int isEmpty(struct Stack* S) {
    return (S->top == -1);
}

int Size(struct Stack* S) {
    return (S->top + 1);
}

int isFull(struct Stack* S) {
    return (S->top == S->array.size() - 1);  // Use vector's size() instead of capacity
}

void Push(struct Stack* S, int data) {
    if (isFull(S)) {
        std::cerr << "Stack Overflow\n";
        // Resize the vector to double its size if full
        S->array.resize(S->array.size() * 2);
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
    delete S;  // No need to manually delete array; vector handles this
}

int main() {
    int capacity = 5;
    struct Stack* stk = createStack(capacity);

    if (!stk) {
        std::cerr << "Failed to create stack\n";
        return 1;
    }

    for (int i = 0; i < capacity; i++) {
        Push(stk, i);
    }

    std::cout << "Top Element: " << Peek(stk) << std::endl;
    std::cout << "Stack Size: " << Size(stk) << std::endl;

    // Pop all elements
    std::cout << "Popped Elements: ";
    for (int i = 0; i < capacity; i++) {
        std::cout << Pop(stk) << " ";
    }
    std::cout << std::endl;

    if (isEmpty(stk)) {
        std::cout << "Stack is Empty\n";
    }
    else {
        std::cout << "Stack is not Empty\n";
    }

    deleteStack(stk);
    return 0;
}
