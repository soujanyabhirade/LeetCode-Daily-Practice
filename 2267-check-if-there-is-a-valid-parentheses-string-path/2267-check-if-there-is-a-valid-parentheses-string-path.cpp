class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        int startBalance = (grid[0][0] == '(' ? 1 : -1);

        if (startBalance < 0)
            return false;

        dp[0][0][startBalance] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int balance = 0; balance < m + n; balance++) {
                    if (!dp[i][j][balance])
                        continue;

                    // Move down
                    if (i + 1 < m) {
                        int newBalance = balance +
                            (grid[i + 1][j] == '(' ? 1 : -1);

                        if (newBalance >= 0)
                            dp[i + 1][j][newBalance] = true;
                    }

                    // Move right
                    if (j + 1 < n) {
                        int newBalance = balance +
                            (grid[i][j + 1] == '(' ? 1 : -1);

                        if (newBalance >= 0)
                            dp[i][j + 1][newBalance] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};