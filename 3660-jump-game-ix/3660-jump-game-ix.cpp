class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        // Graph edges can be represented by the following observation:
        // If i can jump to j, then:
        //   i < j  => nums[j] < nums[i]
        //   i > j  => nums[j] > nums[i]
        //
        // We process values from largest to smallest and maintain
        // connected reachable ranges.

        vector<int> ans(n);

        // Sort indices by value
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        // DSU
        vector<int> parent(n), mx(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            mx[i] = nums[i];
        }

        function<int(int)> find = [&](int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return;

            parent[b] = a;
            mx[a] = max(mx[a], mx[b]);
        };

        /*
         * For every value, indices on its left with a greater value
         * and indices on its right with a smaller value can be connected.
         *
         * We can identify the necessary boundaries using prefix/suffix
         * extrema.
         */

        vector<int> prefMax(n);
        vector<int> suffMin(n);

        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefMax[i] = max(prefMax[i - 1], nums[i]);

        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffMin[i] = min(suffMin[i + 1], nums[i]);

        // Build components.
        // A boundary can be crossed when there is a valid jump across it.
        int start = 0;

        for (int i = 0; i < n - 1; i++) {
            if (prefMax[i] > suffMin[i + 1]) {
                unite(i, i + 1);
            }
        }

        for (int i = 0; i < n; i++) {
            ans[i] = mx[find(i)];
        }

        return ans;
    }
};