class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>Result;
        if(root==NULL){
            return Result;
        }
        map<int, int>mp;
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            Node* frontNode = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            mp[dis] = frontNode->data;
            if(frontNode->left) q.push({frontNode->left, dis-1});
            if(frontNode->right)q.push({frontNode->right, dis+1});
        }
        for(auto i:mp){
            Result.push_back(i.second);
        }
        return Result;
    }
};
