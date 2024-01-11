char solve(MinHeapNode* root, string &s, int &i)
{
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    if(s[i] == '0'){ // Use '==' for comparison instead of '='
        i++;
        return solve(root->left, s, i); // Use -> instead of .
    }
    else{
        i++;
        return solve(root->right, s, i); // Use -> instead of .
    }
}

string decode_file(struct MinHeapNode* root, string s)
{
    string ans = "";
    int i = 0;
    while(i < s.length()){
        ans += solve(root, s, i);
    }
    return ans;
}
