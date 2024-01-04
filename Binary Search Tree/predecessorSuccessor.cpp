pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
        std::pair<int, int> ans = std::make_pair(-1, -1);

        while (root != nullptr) {
            if (root->data == key) {
                // Node with key found
                if (root->left != nullptr) {
                    // If the left subtree exists, find the maximum value in the left subtree
                    TreeNode* predecessorNode = root->left;
                    while (predecessorNode->right != nullptr) {
                        predecessorNode = predecessorNode->right;
                    }
                    ans.first = predecessorNode->data;
                }

                if (root->right != nullptr) {
                    // If the right subtree exists, find the minimum value in the right subtree
                    TreeNode* successorNode = root->right;
                    while (successorNode->left != nullptr) {
                        successorNode = successorNode->left;
                    }
                    ans.second = successorNode->data;
                }

                return ans;
            } else if (key < root->data) {
                // Move to the left subtree
                ans.second = root->data;  // current node could be a successor
                root = root->left;
            } else {
                // Move to the right subtree
                ans.first = root->data;   // current node could be a predecessor
                root = root->right;
            }
        }

        return ans;    
}
