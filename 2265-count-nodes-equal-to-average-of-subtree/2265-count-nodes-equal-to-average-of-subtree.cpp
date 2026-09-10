class Solution {
public:
    pair<int, int> dfs(TreeNode* root, int &ans) {
        if (root == NULL)
            return {0, 0};

        // Get sum and count from left and right subtrees
        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Average is automatically rounded down with integer division
        if (root->val == sum / count)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};