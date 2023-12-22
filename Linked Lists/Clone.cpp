class Solution {
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *copyList(Node *head) {
        if (!head) return nullptr;

        // Step 1: Create a new node for each original node and insert it next to the original node.
        Node* curr = head;
        while (curr != nullptr) {
            Node* newNode = new Node(curr->data);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Copy arbitrary pointers.
        curr = head;
        while (curr != nullptr) {
            if (curr->arb != nullptr) {
                curr->next->arb = curr->arb->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the cloned list from the original list.
        Node* original = head;
        Node* clone = head->next;
        Node* result = clone;

        while (original != nullptr && clone != nullptr) {
            original->next = clone->next;
            original = original->next;

            if (original != nullptr) {
                clone->next = original->next;
                clone = clone->next;
            }
        }

        return result;
    }
};
