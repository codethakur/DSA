bool solve(Node* root,int &cnt,int &node,int &val){
    if(root==NULL) return 0;
    
    if(root->data==node){
        return 1;
    }
    int l=solve(root->left,cnt,node,val);
   
    int r=solve(root->right,cnt,node,val);
    
    if(l||r){
        cnt--;
        if(cnt==0) val=root->data;
        
        return 1;
    }
    
    return 0;
   
}

int kthAncestor(Node *root, int k, int node)
{
    
    int cnt=k;
    int val=-1;
    
    solve(root,cnt,node,val);
    
    return val;
}
