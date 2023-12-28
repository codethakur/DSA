class Solution {
public:
    int pathSumFromRoot(TreeNode * root, long int targetSum){
        int count=0;
        if (root->val == targetSum) count++;
        if (root->left){
            count += pathSumFromRoot(root->left, targetSum-root->val);
        } 
        if (root->right){
            count += pathSumFromRoot(root->right, targetSum-root->val);
        }
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        int count = pathSumFromRoot(root, targetSum);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }
};
