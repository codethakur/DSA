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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        vector<TreeNode*> level;
        vector<TreeNode*> queue{root};
        while (!queue.empty() && root != nullptr) {
            for (auto node : queue) {
                if (node->left) {
                    level.push_back(node->left);
                }
                if (node->right) {
                    level.push_back(node->right);
                }
            }
            output.push_back(queue.back()->val);
            queue = level;
            level.clear();
        }
        return output;
    }
};
/*   
Beats
100.00%
of users with C++*/
 void Solve(TreeNode *root, vector<int> &ans, int level) {
    if (root == NULL) {
        return;
    }
    if (level == ans.size()) {
        ans.push_back(root->val);
    }
    Solve(root->right, ans, level + 1);
    Solve(root->left, ans, level + 1);
    
}
    vector<int> rightSideView(TreeNode* root) {
         vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        Solve(root, ans, 0);
        return ans;
    }
