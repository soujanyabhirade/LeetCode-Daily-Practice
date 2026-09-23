class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        // Prefix sums for each column
        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                pref[j][i + 1] = pref[j][i] + grid[i][j];
            }
        }

        const long long NEG = -(1LL << 60);

        // dp[cur][prev]
        vector<vector<long long>> dp(
            n + 1, vector<long long>(n + 1, NEG)
        );

        // Before first column, previous height = 0
        for (int cur = 0; cur <= n; cur++) {
            dp[cur][0] = 0;
        }

        for (int col = 0; col < n - 1; col++) {

            vector<vector<long long>> ndp(
                n + 1, vector<long long>(n + 1, NEG)
            );

            for (int cur = 0; cur <= n; cur++) {

                // prefixMax[x] =
                // max(dp[cur][prev]) for prev <= x
                vector<long long> prefixMax(n + 1, NEG);

                prefixMax[0] = dp[cur][0];

                for (int prev = 1; prev <= n; prev++) {
                    prefixMax[prev] =
                        max(prefixMax[prev - 1], dp[cur][prev]);
                }

                // suffixMax[x] =
                // max(dp[cur][prev] + pref[col][prev] - pref[col][cur])
                // for prev >= x
                vector<long long> suffixMax(n + 2, NEG);

                for (int prev = n; prev >= 0; prev--) {

                    long long value = NEG;

                    if (dp[cur][prev] != NEG) {
                        value = dp[cur][prev]
                              + max(0LL,
                                    pref[col][prev] - pref[col][cur]);
                    }

                    suffixMax[prev] =
                        max(suffixMax[prev + 1], value);
                }

                // Choose height of next column
                for (int next = 0; next <= n; next++) {

                    // Case 1: prev <= next
                    long long add =
                        max(0LL,
                            pref[col][next] - pref[col][cur]);

                    long long best1 = NEG;

                    if (prefixMax[next] != NEG) {
                        best1 = prefixMax[next] + add;
                    }

                    // Case 2: prev > next
                    long long best2 = suffixMax[next + 1];

                    ndp[next][cur] =
                        max(best1, best2);
                }
            }

            dp.swap(ndp);
        }

        // Last column
        long long ans = 0;

        for (int cur = 0; cur <= n; cur++) {
            for (int prev = 0; prev <= n; prev++) {

                if (dp[cur][prev] == NEG)
                    continue;

                long long gain =
                    max(0LL,
                        pref[n - 1][prev] -
                        pref[n - 1][cur]);

                ans = max(ans, dp[cur][prev] + gain);
            }
        }

        return ans;
    }
};