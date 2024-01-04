// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
     int slv(Node *root, int &i, int K) 
     {
        if (root == NULL) {
            return -1;
        }

        int right = slv(root->right, i, K);
        if (right != -1) {
            return right;
        }

        i++;
        if (i == K) {
            return root->data;
        }

        int left = slv(root->left, i, K);
        return left;
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int i = 0;
        return slv(root, i, K);;
        
    }
};
