#include <iostream>

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to reverse a linked list from 'start' to 'end' node
Node* reverseList(Node* start, Node* end) {
    Node* prev = end->next;
    Node* curr = start;
    while (prev != end) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}



Node* reverseBlockOfKthNodeInLL(Node* head, int k) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* groupPrev = dummy, *end=head;


    int i =0;
    while (end!=NULL)
    {
        i++;
        if(i%k==0){
            Node* Start=groupPrev->next, *NextGroup=end->next;
            reverseList(Start, end);
            groupPrev->next=end;
            Start->next=NextGroup;
            groupPrev=Start;
            end=NextGroup;


        }else{
            end=end->next;
        }
    }
    return dummy->next;
     
}

// Helper function to insert a new node at the end of the list
void insertAtEnd(Node **head, int data) {
    Node *newNode = new Node(data);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Helper function to print the linked list
void printList(Node *head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Node *head1 = nullptr;
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head1, 4);
    insertAtEnd(&head1, 5);
    insertAtEnd(&head1, 6);
    insertAtEnd(&head1, 7);
    insertAtEnd(&head1, 8);
    insertAtEnd(&head1, 9);
    insertAtEnd(&head1, 10);

    std::cout << "Original List: " << std::endl;
    printList(head1);

    Node *reversedHead = reverseBlockOfKthNodeInLL(head1, 3);
    std::cout << "List after reversing every 3 nodes: " << std::endl;
    printList(reversedHead);

    return 0;
}
