/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int &res)
    {
        if(root==NULL)
            return 0;
            int left = solve(root->left, res);
            int right = solve(root->right, res);

            int result = max(left, right) + root->val;
          // if that node getting -ve val and they want give there own val only if that node to be leaf node.
            if(root->left==NULL && root->right==NULL)
              result = max(result, root->val);
      
            int result1 = max(result, left+right+root->val);

            res=max(res, result1);

            return result;
    }
    int maxPathSum(TreeNode* root) {
        int res= INT_MIN;
        solve(root, res);
        return res;

    }
};
