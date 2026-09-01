class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();

        // Length must match
        if (m + n != s3.length())
            return false;

        // dp[i][j] = whether first i chars of s1
        // and first j chars of s2 can form
        // first i+j chars of s3
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {

                if (i == 0 && j == 0)
                    continue;

                // Take character from s1
                if (i > 0 && 
                    dp[i - 1][j] && 
                    s1[i - 1] == s3[i + j - 1]) {
                    
                    dp[i][j] = true;
                }

                // Take character from s2
                if (j > 0 && 
                    dp[i][j - 1] && 
                    s2[j - 1] == s3[i + j - 1]) {
                    
                    dp[i][j] = true;
                }
            }
        }

        return dp[m][n];
    }
};