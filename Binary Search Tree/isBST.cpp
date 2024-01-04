class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool slv(Node* root, int min, int max)
    {
        if (root == NULL)
        {
            return true;
        }
        
        if (root->data > min && root->data < max)
        {
            bool left = slv(root->left, min, root->data);
            bool right = slv(root->right, root->data, max);
    
            return left && right;
        }
        else
        {
            return false;
        }
    }
    bool isBST(Node* root) 
    {
        // Your code here
      return slv(root, INT_MIN, INT_MAX);
    }
};
