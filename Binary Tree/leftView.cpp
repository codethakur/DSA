void Solve(Node *root, vector<int> &ans, int level) {
    if (root == NULL) {
        return;
    }
    if (level == ans.size()) {
        ans.push_back(root->data);
    }
    Solve(root->left, ans, level + 1);
    Solve(root->right, ans, level + 1);
}

vector<int> leftView(Node *root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    Solve(root, ans, 0);
    return ans;
}
