class Solution{
private:
    int height(struct Node* node){
        // code here 
        if(node == NULL)
            return 0;
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        
        return ans;
    }

public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root) {
        // Your Code here
        if (root == NULL) {
            return true; // An empty tree is considered balanced
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
        return left && right && diff;
    }
};
/////////////////////////////110. Balanced Binary Tree-LEETCODE//////////////////////

class Solution {
public:
     pair<bool, int>Balanced(TreeNode* root){
        if(root==NULL)
        {
            pair<bool,int>p = make_pair(true, 0);
            return p;
        }
       std::pair<bool, int> rootleft = Balanced(root->left);
        std::pair<bool, int> rootright = Balanced(root->right);
        
        bool left = rootleft.first;
        bool right  = rootright.first;
        
        bool diff = abs(rootleft.second - rootright.second) <= 1;        
        std::pair<bool, int> ans;
        ans.second = std::max(rootleft.second, rootright.second) + 1;
        
        if(left && right && diff){
            ans.first = true;
        } else {
            ans.first = false;
            //ans.second = 0;  
        }
        return ans;;
        
    }
    bool isBalanced(TreeNode* root) {
        return Balanced(root).first;
    }
};
