struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 


class Solution {
  private:
    int height(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left, right) + 1;

        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int leftDiameter = diameter(root->left);
        int rightDiameter = diameter(root->right);

        // Calculate the diameter passing through the current root
        int totalDiameter = leftHeight + rightHeight + 1;

        // Return the maximum of the three diameters
        return max({leftDiameter, rightDiameter, totalDiameter});
    }
/*
    Test Cases Passed: 
    535 /1311 => O(n^2)
    Time Limit Exceeded
*/
};
///////////////////////Time Complexity: O(N)///////////////////////////
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int, int>FindDiameter(Node* root)
    {
        if(root==NULL){
            pair<int, int>p=make_pair(0,0);
            return p;
        }
        pair<int, int>left = FindDiameter(root->left);
        pair<int, int>right = FindDiameter(root->right);
        
        int op1 = left.first; //height
        int op2 = right.second;//height
        int op3 = left.second +right.second + 1; //diameter
        
        pair<int, int> ans;
        ans.first = max(op3, max(op1, op2));
        ans.second = max(left.second, right.second)+1;
        
        return ans;
        
    }
    int diameter(Node* root) {
        // Your code here
        return FindDiameter(root).first;
    }
};
