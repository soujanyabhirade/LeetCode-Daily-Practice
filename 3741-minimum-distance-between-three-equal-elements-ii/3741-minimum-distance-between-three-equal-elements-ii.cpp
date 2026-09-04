class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // positions[x] stores the last two indices of x
        vector<vector<int>> positions(n + 1);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            positions[x].push_back(i);

            if (positions[x].size() >= 3) {
                int m = positions[x].size();

                int first = positions[x][m - 3];
                int last = positions[x][m - 1];

                int distance = 2 * (last - first);

                ans = min(ans, distance);

                // Keep only the last two positions
                positions[x].erase(positions[x].begin());
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};