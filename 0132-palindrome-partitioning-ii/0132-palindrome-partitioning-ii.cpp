class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        // palindrome[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }

        // dp[i] = minimum cuts needed for s[0...i]
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = i;  // Worst case: cut before every character

            for (int j = 0; j <= i; j++) {
                if (palindrome[j][i]) {
                    if (j == 0) {
                        dp[i] = 0;
                    } else {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};