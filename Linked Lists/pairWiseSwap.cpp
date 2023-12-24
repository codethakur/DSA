class Solution
{
public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if (head == NULL || head->next == NULL) {
            return head;
        }

        struct Node* dummyNode = new Node(0);
        struct Node* prev = dummyNode;
        dummyNode->next = head;

        while (head != NULL && head->next != NULL) {
            struct Node* first = head;
            struct Node* second = first->next;
            struct Node* RemainNode = second->next;

            // Swap nodes
            prev->next = second;
            second->next = first;
            first->next = RemainNode;

            // Move to the next pair
            prev = first;
            head = RemainNode;
        }

        struct Node* NewList = dummyNode->next;
        delete dummyNode;
        return NewList;
    }
};
