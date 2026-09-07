class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();

        // Store all positions of each character in ring
        vector<vector<int>> pos(26);

        for (int i = 0; i < n; i++) {
            pos[ring[i] - 'a'].push_back(i);
        }

        const int INF = 1e9;

        // dp[i] = minimum cost when ring is currently at position i
        vector<int> dp(n, INF);

        // Initially position 0 is at 12:00
        dp[0] = 0;

        for (char c : key) {
            vector<int> ndp(n, INF);

            for (int i = 0; i < n; i++) {
                if (dp[i] == INF)
                    continue;

                // Try every occurrence of the required character
                for (int j : pos[c - 'a']) {

                    // Minimum clockwise / anticlockwise rotation
                    int diff = abs(i - j);
                    int rotate = min(diff, n - diff);

                    ndp[j] = min(
                        ndp[j],
                        dp[i] + rotate + 1
                    );
                }
            }

            dp = ndp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};