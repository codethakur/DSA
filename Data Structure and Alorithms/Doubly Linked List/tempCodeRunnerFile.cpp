#include <iostream>

struct DLLNode {
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
};

void insertAtBeginning(struct DLLNode **head, int data) {
    struct DLLNode *current = *head;
    struct DLLNode *newNode = new DLLNode();
    
    if (!newNode) {
        return;
    }
    
    newNode->prev = nullptr;
    newNode->data = data;
    newNode->next = *head;

    if (current == nullptr) {
        *head = newNode;
        return;
    }
    
    (*head)->prev = newNode;
    *head = newNode;
}

void Print(struct DLLNode *head) {
    struct DLLNode *temp = head;

    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
            std::cout << " -> ";
        } else {
            std::cout << " -> NULL";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Start from Now!!" << std::endl;

    struct DLLNode *head = nullptr; // Initialize head to nullptr
    insertAtBeginning(&head, 15);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 40);

    Print(head);

    std::cin.get();
    return 0;
}
