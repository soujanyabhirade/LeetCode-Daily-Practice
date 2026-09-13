class Solution {
public:
    int minimumHammingDistance(vector<int>& source,
                               vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        
        int n = source.size();

        // DSU
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);

            if (a != b)
                parent[b] = a;
        };

        // Connect indices that can be swapped
        for (auto& swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }

        // Group values by connected component
        unordered_map<int, unordered_map<int, int>> groups;

        for (int i = 0; i < n; i++) {
            groups[find(i)][source[i]]++;
        }

        int ans = 0;

        // Match target values with source values
        for (int i = 0; i < n; i++) {
            int root = find(i);

            if (groups[root][target[i]] > 0) {
                groups[root][target[i]]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};