struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* head = nullptr;
    Node* prev = nullptr;

    void convertToDLL(Node* root) {
        if (!root) {
            return;
        }

        // Recursively convert the left subtree
        convertToDLL(root->left);

        // Modify pointers to create the doubly linked list
        if (!prev) {
            // First node encountered, update the head
            head = root;
        } else {
            // Update the right pointer of the previous node
            prev->right = root;
            // Update the left pointer of the current node
            root->left = prev;
        }

        // Update the previous pointer for the next iteration
        prev = root;

        // Recursively convert the right subtree
        convertToDLL(root->right);
    }

    Node* bToDLL(Node* root) {
        // Reset the global variables
        head = nullptr;
        prev = nullptr;

        // Convert the binary tree to doubly linked list
        convertToDLL(root);

        return head;
    }
};
