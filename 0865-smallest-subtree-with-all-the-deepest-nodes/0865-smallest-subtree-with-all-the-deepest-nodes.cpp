class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {nullptr, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Both sides have deepest nodes at the same depth
        if (left.second == right.second) {
            return {root, left.second + 1};
        }

        // Left subtree is deeper
        if (left.second > right.second) {
            return {left.first, left.second + 1};
        }

        // Right subtree is deeper
        return {right.first, right.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};