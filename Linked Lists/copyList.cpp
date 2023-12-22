#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;                        //TC = O(N) , S.C. = O(N)
    }
};

class Solution {
private:
    void insertAtTailNode(Node* &head, Node* &tail, int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node* copyList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while (temp != NULL) {
            insertAtTailNode(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        unordered_map<Node*, Node*> cloneToOriginalNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while (originalNode != NULL) {
            cloneToOriginalNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            if (originalNode != NULL) {
                cloneNode = cloneNode->next;
            }
        }

        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL) {
            cloneNode->arb = cloneToOriginalNode[originalNode->arb];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};

// Example usage:
int main() {
    // Create a linked list for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->arb = head->next->next;
    head->next->arb = head;
    
    Solution solution;
    Node* clonedList = solution.copyList(head);

    // Add any necessary code to print or validate the result

    return 0;
}
