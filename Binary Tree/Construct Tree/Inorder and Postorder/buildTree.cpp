class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Create a map to store the index of each element in inorder traversal
        unordered_map<int, int> mymap;
        for (int i = 0; i < inorder.size(); i++) {
            mymap[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1; // Start from the end of postorder
        return build_fn(inorder, postorder, 0, inorder.size() - 1, postIndex, mymap);
    }

private:
    TreeNode* build_fn(vector<int>& inorder, vector<int>& postorder, int start, int end, int& postIndex, unordered_map<int, int>& mymap) {
        if (start > end)
            return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int index = mymap[rootVal];

        // Build the right subtree first (because postorder is right-root-left)
        root->right = build_fn(inorder, postorder, index + 1, end, postIndex, mymap);
        // Build the left subtree
        root->left = build_fn(inorder, postorder, start, index - 1, postIndex, mymap);

        return root;
    }
};
