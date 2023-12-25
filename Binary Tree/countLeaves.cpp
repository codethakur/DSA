void inOrder(Node* root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    
    inOrder(root->right, count);
}   
int countLeaves(Node* root)
{
  // Your code here
  int cnt=0;
  inOrder(root, cnt);
  return cnt;
}
