#include <iostream>
#include <stack>

// Helper function to delete the middle element
void Solve(std::stack<int>& st, int k) {
    if (k == 1) {
        // Base case: Remove the middle element
        st.pop();
        return;
    }

    int tempVar = st.top();
    st.pop();

    // Recursive call to move towards the middle
    Solve(st, k - 1);

    // Push the elements back after removing the middle element
    st.push(tempVar);
}

// Function to delete the middle element
std::stack<int> DeleteMidEle(std::stack<int>& st) {
    if (st.empty()) {
        return st;
    }

    int k = st.size() / 2 + 1; // Find the middle index (1-based indexing)
    Solve(st, k);

    return st;
}

int main() {
    std::stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    auto output = DeleteMidEle(st);

    // Print the stack after deleting the middle element
    while (!output.empty()) {
        std::cout << output.top() << std::endl;
        output.pop();
    }

    return 0;
}
 