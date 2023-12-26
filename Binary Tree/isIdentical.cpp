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
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // Your Code here
        if (r1 == NULL && r2 == NULL) {
            return true;
        }
        if (r1 != NULL && r2 != NULL) {
            bool rootleft = isIdentical(r1->left, r2->left);
            bool rootright = isIdentical(r1->right, r2->right);
            bool value = r1->data == r2->data;

            // Use logical AND to combine the conditions
            return rootleft && rootright && value;
        }
        // If one of them is NULL and the other is not, they are not identical.
        return false;
    }
};
