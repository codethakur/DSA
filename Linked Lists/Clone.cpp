class Solution
{
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
    Node *copyList(Node *head)
    {
        //Write your code here
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

        unordered_map<Node*, Node*> OriginalNodeToclone;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while (originalNode != NULL) {
            OriginalNodeToclone[originalNode] = cloneNode;
            originalNode = originalNode->next;
            if (originalNode != NULL) {
                cloneNode = cloneNode->next;
            }
        }

        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL) {
            cloneNode->arb = OriginalNodeToclone[originalNode->arb];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;        
    }

};
/////////////////////////////////////////
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
