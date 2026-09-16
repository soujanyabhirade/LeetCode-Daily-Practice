class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1000000007;

        vector<vector<long long>> dp(k + 1,
                                     vector<long long>(n, 0));

        // 0 segments: one way
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;

        for (int seg = 1; seg <= k; seg++) {
            long long sum = 0;

            for (int i = 1; i < n; i++) {
                // Starting a new segment at some point <= i-1
                sum = (sum + dp[seg - 1][i - 1]) % MOD;

                // Don't end a segment at i
                dp[seg][i] = dp[seg][i - 1];

                // Add ways where the last segment ends at i
                dp[seg][i] = (dp[seg][i] + sum) % MOD;
            }
        }

        return dp[k][n - 1];
    }
};