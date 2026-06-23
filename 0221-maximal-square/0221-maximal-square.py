class Solution(object):
    def maximalSquare(self, matrix):
        if not matrix:
            return 0

        m, n = len(matrix), len(matrix[0])

        # DP table with extra row and column
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        max_side = 0

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if matrix[i - 1][j - 1] == '1':
                    dp[i][j] = 1 + min(
                        dp[i - 1][j],      # top
                        dp[i][j - 1],      # left
                        dp[i - 1][j - 1]   # top-left
                    )

                    max_side = max(max_side, dp[i][j])

        return max_side * max_side