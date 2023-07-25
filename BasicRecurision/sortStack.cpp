//https://www.codingninjas.com/studio/problems/sort-a-stack_985275?leftPanelTab=0
//codingninjas

#include <iostream>
#include <stack>

void insertTemp(std::stack<int>& st, int temp) {
    if (st.empty() || st.top() < temp) {
        st.push(temp);
        return;
    }

    int val = st.top();
    st.pop();
    insertTemp(st, temp);
    st.push(val);
}

void sortStack(std::stack<int>& stack) {
    if (stack.size() == 0 || stack.size() == 1) return;

    int temp = stack.top();
    stack.pop();
    sortStack(stack);
    insertTemp(stack, temp);
}

int main() {
    std::stack<int> myStack;

    // Push elements into the stack (unsorted)
    myStack.push(5);
    myStack.push(2);
    myStack.push(7);
    myStack.push(1);
    myStack.push(3);

    // Sort the stack in descending order
    sortStack(myStack);

    // Print the sorted stack
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}
