class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Find all palindromes
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum palindromes using s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            // Skip this character
            dp[i + 1] = max(dp[i + 1], dp[i]);

            // Try every palindrome starting at i
            for (int j = i + k - 1; j < n; j++) {
                if (pal[i][j]) {
                    dp[j + 1] = max(dp[j + 1], dp[i] + 1);
                }
            }
        }

        return dp[n];
    }
};