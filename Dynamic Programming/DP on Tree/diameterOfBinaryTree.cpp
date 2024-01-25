class Solution {
    int solve(TreeNode* root , int &res){
        if(root == NULL) return 0;
        
        int left = solve(root->left,res);
        int right = solve(root->right,res);
        
        int temp = max(left, right)+1;
        int ans = max(temp , left+right+1);
        res = max(res,ans);
        
        return temp;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = -1;
        
        solve(root , res);
        return res-1;
    }
};
