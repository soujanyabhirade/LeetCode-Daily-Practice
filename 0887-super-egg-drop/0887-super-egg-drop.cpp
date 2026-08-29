class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<long long> dp(k + 1, 0);

        int moves = 0;

        while (dp[k] < n) {
            moves++;

            // Go backwards so dp[e-1] is still from
            // the previous number of moves.
            for (int e = k; e >= 1; e--) {
                dp[e] = dp[e] + dp[e - 1] + 1;
            }
        }

        return moves;
    }
};