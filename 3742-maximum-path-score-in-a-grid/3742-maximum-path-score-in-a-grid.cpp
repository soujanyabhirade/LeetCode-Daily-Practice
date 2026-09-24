class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        const int NEG = -1e9;

        // dp[j][c] = maximum score reaching current row, column j
        // with exactly c cost
        vector<vector<int>> dp(n, vector<int>(k + 1, NEG));

        int cost = (grid[0][0] > 0);
        int score = grid[0][0];

        if (cost <= k)
            dp[0][cost] = score;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int cellCost = (grid[i][j] > 0);
                int cellScore = grid[i][j];

                vector<int> cur(k + 1, NEG);

                // From top
                if (i > 0) {
                    for (int c = cellCost; c <= k; c++) {
                        if (dp[j][c - cellCost] != NEG) {
                            cur[c] = max(
                                cur[c],
                                dp[j][c - cellCost] + cellScore
                            );
                        }
                    }
                }

                // From left
                if (j > 0) {
                    for (int c = cellCost; c <= k; c++) {
                        if (dp[j - 1][c - cellCost] != NEG) {
                            cur[c] = max(
                                cur[c],
                                dp[j - 1][c - cellCost] + cellScore
                            );
                        }
                    }
                }

                dp[j] = cur;
            }
        }

        int ans = -1;

        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n - 1][c]);
        }

        return ans == NEG ? -1 : ans;
    }
};