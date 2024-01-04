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
//////////////////////// Type 2/////////////////////////////
class Solution {
public:
    vector<int>Node;
       void inorder(TreeNode* root)
       {
           if(root->left) inorder(root->left);
            Node.push_back(root->val);
            if(root->right)
            inorder(root->right);
       } 
    bool isValidBST(TreeNode* root) {
       inorder(root);
       for(int i =0; i<Node.size()-1; i++)
       {
           if(Node[i]>= Node[i+1]) return false;
       }
       return true;
    }
};
