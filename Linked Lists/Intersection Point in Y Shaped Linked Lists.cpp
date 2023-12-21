// Linked List Node
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2) {
    int len1 = 0, len2 = 0;

    // Find the length of the first linked list
    Node* temp = head1;
    while (temp != NULL) {
        len1++;
        temp = temp->next;
    }

    // Find the length of the second linked list
    temp = head2;
    while (temp != NULL) {
        len2++;
        temp = temp->next;
    }

    int diff = abs(len1 - len2);

    // Move the pointer of the longer linked list ahead by diff nodes
    Node* current1 = head1;
    Node* current2 = head2;
    for (int i = 0; i < diff; i++) {
        if (len1 > len2) {
            current1 = current1->next;
        } else {
            current2 = current2->next;
        }
    }

    // Traverse both linked lists in tandem until a common node is found
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2) {
            return current1->data; // Found the intersection point
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return -1; // No intersection point found
}
