class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // Store parent of every node
        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // BFS starting from target
        queue<TreeNode*> bfs;
        unordered_set<TreeNode*> visited;

        bfs.push(target);
        visited.insert(target);

        int distance = 0;

        while (!bfs.empty()) {
            
            int size = bfs.size();

            // We reached distance k
            if (distance == k) {
                vector<int> ans;

                while (!bfs.empty()) {
                    ans.push_back(bfs.front()->val);
                    bfs.pop();
                }

                return ans;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();

                // Left child
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    bfs.push(node->left);
                }

                // Right child
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    bfs.push(node->right);
                }

                // Parent
                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    bfs.push(parent[node]);
                }
            }

            distance++;
        }

        return {};
    }
};