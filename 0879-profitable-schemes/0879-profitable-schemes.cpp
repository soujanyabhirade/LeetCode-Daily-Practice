class Solution {
public:
    int profitableSchemes(int n, int minProfit,
                          vector<int>& group,
                          vector<int>& profit) {

        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(minProfit + 1, 0)
        );

        dp[0][0] = 1;

        for (int i = 0; i < group.size(); i++) {

            int g = group[i];
            int p = profit[i];

            for (int members = n; members >= g; members--) {

                for (int currentProfit = minProfit;
                     currentProfit >= 0;
                     currentProfit--) {

                    int newProfit =
                        min(minProfit, currentProfit + p);

                    dp[members][newProfit] =
                        (dp[members][newProfit]
                         + dp[members - g][currentProfit])
                        % MOD;
                }
            }
        }

        int ans = 0;

        // Any number of members <= n is allowed
        // as long as profit >= minProfit.
        for (int members = 0; members <= n; members++) {
            ans = (ans + dp[members][minProfit]) % MOD;
        }

        return ans;
    }
};