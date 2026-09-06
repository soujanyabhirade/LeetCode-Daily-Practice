class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        const long long INF = 1e18;

        // dp[i] = minimum cost to repair the first i robots
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int j = 0; j < m; j++) {
            int pos = factory[j][0];
            int limit = factory[j][1];

            vector<long long> ndp(n + 1, INF);

            // Use this factory for k consecutive robots
            for (int i = 0; i <= n; i++) {
                long long cost = 0;

                for (int k = 0; k <= limit && k <= i; k++) {

                    if (k > 0) {
                        cost += abs((long long)robot[i - k] - pos);
                    }

                    if (dp[i - k] != INF) {
                        ndp[i] = min(ndp[i],
                                     dp[i - k] + cost);
                    }
                }
            }

            dp = ndp;
        }

        return dp[n];
    }
};