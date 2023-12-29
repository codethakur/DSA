/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution {
public:
    map<int, int> mymap;
    int preInd = 0;

    Node* buildTree(int in[], int pre[], int n) {
        for (int i = 0; i < n; i++) {
            mymap[in[i]] = i;
        }

        return build_fn(in, pre, 0, n - 1);
    }

private:
    Node* build_fn(int in[], int pre[], int start, int end) {
        if (start > end)
            return nullptr;

        int rootVal = pre[preInd++];
        Node* root = new Node(rootVal);

        int index = mymap[rootVal];

        // Note the order of recursive calls for inorder traversal
        root->left = build_fn(in, pre, start, index - 1);
        root->right = build_fn(in, pre, index + 1, end);

        return root;
    }
};
