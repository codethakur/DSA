//Height of a Binary Tree

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {return 0; }

        int Left = maxDepth(root->left);
        int Right = maxDepth(root->right);

        return max(Left,Right)+1;
    }
};
