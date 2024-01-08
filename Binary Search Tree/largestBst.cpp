class Solution{
    public:
    class info {
    public:
        int mini;
        int maxi;
        bool isBST;
        int size; // Added size member
    };
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    info solve(Node* root, int &ans) {
        if (root == nullptr) {
            return {INT_MAX, INT_MIN, true, 0};
        }

        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        info currNode;

        currNode.size = left.size + right.size + 1;
        currNode.mini = min(root->data, left.mini);
        currNode.maxi = max(root->data, right.maxi);

        if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
            currNode.isBST = true;
            ans = max(ans, currNode.size); 
        } else {
            currNode.isBST = false;
        }

        return currNode;
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	int maxSize = 0;
        info temp = solve(root, maxSize);
        return maxSize;
    }
};
