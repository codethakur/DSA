class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (node->right != nullptr) {
                s.push(node->right);
            }

            if (node->left != nullptr) {
                s.push(node->left);
            }

            // Update the current node's left to null
            node->left = nullptr;

            // Connect the current node to the next node in the list
            if (!s.empty()) {
                node->right = s.top();
            }
        }
    }
};
