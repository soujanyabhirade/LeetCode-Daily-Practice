class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        const int NEG = -1e9;

        // dp[i][j][k] = max profit reaching (i,j)
        // using exactly k neutralizations
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, NEG))
        );

        // Starting cell
        dp[0][0][0] = coins[0][0];

        // We can neutralize the starting robber too
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip starting cell
                if (i == 0 && j == 0)
                    continue;

                for (int k = 0; k <= 2; k++) {

                    // Best value from top or left
                    int best = NEG;

                    if (i > 0)
                        best = max(best, dp[i - 1][j][k]);

                    if (j > 0)
                        best = max(best, dp[i][j - 1][k]);

                    if (best != NEG) {
                        // Don't neutralize this cell
                        dp[i][j][k] = max(
                            dp[i][j][k],
                            best + coins[i][j]
                        );
                    }

                    // Neutralize this cell
                    if (coins[i][j] < 0 && k > 0) {

                        int bestPrev = NEG;

                        if (i > 0)
                            bestPrev = max(bestPrev, dp[i - 1][j][k - 1]);

                        if (j > 0)
                            bestPrev = max(bestPrev, dp[i][j - 1][k - 1]);

                        if (bestPrev != NEG) {
                            dp[i][j][k] = max(
                                dp[i][j][k],
                                bestPrev
                            );
                        }
                    }
                }
            }
        }

        return max({
            dp[m - 1][n - 1][0],
            dp[m - 1][n - 1][1],
            dp[m - 1][n - 1][2]
        });
    }
};