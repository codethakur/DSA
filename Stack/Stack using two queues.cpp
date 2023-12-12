#include <queue>

class QueueStack {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    // Function to push an element into the stack
    void push(int x) {
        // Enqueue the new element into q1
        q1.push(x);
    }

    // Function to pop an element from the stack
    int pop() {
        if (q1.empty()) {
            // Stack is empty
            return -1; // Or any other suitable value to indicate an empty stack
        }

        // Move all elements from q1 to q2, except the last one
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // The last element in q1 is the top element of the stack
        int topElement = q1.front();
        q1.pop();

        // Swap q1 and q2
        std::swap(q1, q2);

        return topElement;
    }
};
