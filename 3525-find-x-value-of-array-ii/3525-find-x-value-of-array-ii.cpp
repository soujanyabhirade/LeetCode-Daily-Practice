class Solution {
public:
    struct Node {
        int prod;
        long long pref[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                pref[i] = 0;
        }
    };

    int n, k;
    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res;

        // Product of the complete segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside a
        for (int r = 0; r < k; r++)
            res.pref[r] = a.pref[r];

        // Prefixes that continue from a into b
        for (int r = 0; r < k; r++) {
            int rem = (a.prod * r) % k;
            res.pref[rem] += b.pref[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int x = nums[l] % k;

            tree[node].prod = x;
            tree[node].pref[x] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            int x = val % k;

            tree[node] = Node();
            tree[node].prod = x;
            tree[node].pref[x] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, r, pos, val);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql) {
        // Completely outside [ql, n-1]
        if (r < ql)
            return Node();

        // Completely inside
        if (ql <= l)
            return tree[node];

        int mid = (l + r) / 2;

        Node left = query(node * 2, l, mid, ql);
        Node right = query(node * 2 + 1, mid + 1, r, ql);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;

        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> result;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update persists for future queries
            update(1, 0, n - 1, index, value);

            // Get information for nums[start ... n-1]
            Node res = query(1, 0, n - 1, start);

            result.push_back(res.pref[x]);
        }

        return result;
    }
};