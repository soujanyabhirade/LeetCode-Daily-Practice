class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        // dp[i] = number of distinct subsequences
        // including the empty subsequence after processing i characters
        long long dp[26] = {0};

        long long total = 1; // empty subsequence

        for (char c : s) {
            int x = c - 'a';

            // All current subsequences can be extended by c.
            // But subsequences ending in c were already counted,
            // so replace them with the new count.
            long long newCount = total;

            total = (total + newCount - dp[x] + MOD) % MOD;

            dp[x] = newCount;
        }

        // Remove the empty subsequence
        return (total - 1 + MOD) % MOD;
    }
};