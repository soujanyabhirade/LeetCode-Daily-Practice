class Solution:
    def isMatch(self, s, p):
        m, n = len(s), len(p)

        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True

        for j in range(2, n + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 2]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    zero_match = dp[i][j - 2]
                    preceding_matches = p[j - 2] == s[i - 1] or p[j - 2] == '.'
                    one_or_more_match = dp[i - 1][j] and preceding_matches
                    dp[i][j] = zero_match or one_or_more_match
                elif p[j - 1] == '.' or p[j - 1] == s[i - 1]:
                    dp[i][j] = dp[i - 1][j - 1]

        return dp[m][n]