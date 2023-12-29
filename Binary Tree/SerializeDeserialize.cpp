struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void preorder(Node *root, vector<int>&res) {
        if(!root){
            res.push_back(-1);
            return;
        }
        res.push_back(root->data);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>res;
        preorder(root, res);
        return res;
    }
     Node * makeTree(vector<int>&a, int &index) {
        int value = a[index++];
        if(value == -1) return NULL;
        Node *root = new Node(value);
        root->left = makeTree(a, index);
        root->right = makeTree(a, index);
        return root;
    }
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
        int index = 0;
        return makeTree(A, index);
    }
