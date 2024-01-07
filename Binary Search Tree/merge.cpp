class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
        vector<int> bst1, bst2;
        inOrder(root1, bst1);
        inOrder(root2, bst2);
        vector<int> mergeArray = mergeArrays(bst1, bst2);
        return mergeArray;
    }
    void inOrder(Node* root, vector<int>& in) {
        if (root == nullptr)
            return;
        inOrder(root->left, in);
        in.push_back(root->data);
        inOrder(root->right, in);
    }
     vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
        vector<int> ans(a.size() + b.size());
        int i = 0, j = 0, k = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                ans[k++] = a[i++];
            } else {
                ans[k++] = b[j++];
            }
        }
        while (i < a.size()) {
            ans[k++] = a[i++];
        }
        while (j < b.size()) {
            ans[k++] = b[j++];
        }
        return ans;
    }

    Node* inOrderToBST(int s, int e, vector<int>& in) {
        if (s > e)
            return nullptr;
        int mid = (s + e) / 2;
        Node* root = new Node(in[mid]);
        root->left = inOrderToBST(s, mid - 1, in);
        root->right = inOrderToBST(mid + 1, e, in);
        return root;
    }
};
