class Solution:
    def numDecodings(self, s):
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 0 if s[0] == '0' else 1

        for i in range(2, n + 1):
            one_digit = int(s[i - 1])
            two_digit = int(s[i - 2 : i])

            if one_digit >= 1:
                dp[i] += dp[i - 1]

            if 10 <= two_digit <= 26:
                dp[i] += dp[i - 2]

        return dp[n]
        