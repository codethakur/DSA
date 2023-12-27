class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};  // Handle the case where the root is nullptr

        vector<vector<int>> Result;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; // left to right

        while (!q.empty()) {
            int Size = q.size();
            vector<int> TempAns(Size);

            for (int i = 0; i < Size; i++) {  
                TreeNode* frontNode = q.front();
                q.pop();
                int index = flag ? i : Size - i - 1;

                TempAns[index] = frontNode->val;

                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            Result.push_back(TempAns);
            flag = !flag;  // Switch the direction for the next level
        }

        return Result;
    }
};
