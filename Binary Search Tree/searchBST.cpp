class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
         if (root == nullptr) {
            return nullptr;
        }
        
        if (root->val == val) {
            return root;
        }
        
        TreeNode* temp = root;
        while (temp != nullptr) {
            if (temp->val == val) {
                return temp;  // Found the node with the given value
            } else if (temp->val > val) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        
        return nullptr;  // If no node with the given value is found
    }
};
