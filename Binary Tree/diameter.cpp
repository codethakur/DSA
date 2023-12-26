struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

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
};
