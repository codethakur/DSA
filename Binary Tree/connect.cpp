class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       if(root==NULL){
           return;
       }
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty())
       {
           int size = q.size();
           for(int i =0; i<size; i++)
           {
               Node*curr= q.front();
               q.pop();
               
               if(i<size-1){
                   curr->nextRight=q.front();
               }
               if(curr->left){
                   q.push(curr->left);
               }
               if(curr->right){
                   q.push(curr->right);
               }
           }
       }
    }    
      
};
