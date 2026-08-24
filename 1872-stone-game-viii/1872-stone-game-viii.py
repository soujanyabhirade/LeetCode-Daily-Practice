class Solution:
    def stoneGameVIII(self, stones):
        n = len(stones)

        # prefix sum
        prefix = [0] * n
        prefix[0] = stones[0]

        for i in range(1, n):
            prefix[i] = prefix[i - 1] + stones[i]

        # Start with the only possible final merge:
        # prefix[n - 1]
        ans = prefix[n - 1]

        # Work backwards.
        # We need at least 2 stones to make a move,
        # so i starts from n - 2.
        for i in range(n - 2, 0, -1):
            ans = max(ans, prefix[i] - ans)

        return ans