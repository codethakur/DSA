class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int>Result;
        if(root==NULL){
            return Result;
        }
        map<int,vector<int>>mp;
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            Node* frontNode = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            mp[dis].push_back(frontNode->data);
            
            if(frontNode->left)q.push({frontNode->left,dis-1});
            if(frontNode->right)q.push({frontNode->right,dis+1});
        }
        for(auto i:mp){
            for(auto j:i.second ){
                Result.push_back(j);
            }
        }
        return Result;
    }
};
