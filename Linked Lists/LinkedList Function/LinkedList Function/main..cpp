#include "Node.h"
#include "LinkedListFunctions.h"

int main() {
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;
    printList(head);

    insertAtTail(tail, 12);
    printList(head);

    insertAtTail(tail, 15);
    printList(head);

    insertAtPosition(tail, head, 14, 2);
    printList(head);

    insertAtPosition(tail, head, 22, 4);
    printList(head);

    deleteNode(tail, head, 1);
    printList(head);

    return 0;
}
