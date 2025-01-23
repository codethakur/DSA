#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Recursive function to add two numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
    // Base case: if both lists are empty and carry is 0
    if (!l1 && !l2 && carry == 0) {
        return nullptr;
    }

    int sum = carry;
    
    // Add l1's value if it exists
    if (l1) {
        sum += l1->val;
        l1 = l1->next;
    }

    // Add l2's value if it exists
    if (l2) {
        sum += l2->val;
        l2 = l2->next;
    }

    // Create a new node with the digit part of the sum
    ListNode* node = new ListNode(sum % 10);

    // Recursive call for the next nodes
    node->next = addTwoNumbers(l1, l2, sum / 10);

    return node;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr1[] = {2, 4, 3};  // Represents 342
    int arr2[] = {5, 6, 4};  // Represents 465

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    ListNode* result = addTwoNumbers(l1, l2);

    std::cout << "Result: ";
    printList(result);  // Output: 7 -> 0 -> 8

    return 0;
}
