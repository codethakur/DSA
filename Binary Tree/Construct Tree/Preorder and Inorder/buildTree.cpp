class Solution {
public:
    map<int, int> mymap;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mymap[inorder[i]] = i;
        }

        return build_fn(preorder, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build_fn(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (start > end)
            return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int index = mymap[rootVal];

        root->left = build_fn(preorder, inorder, start, index - 1);
        root->right = build_fn(preorder, inorder, index + 1, end);

        return root;
    }
};
