class Solution:
    def new21Game(self, n, k, maxPts):
        # If Alice stops immediately
        if k == 0:
            return 1.0

        # Maximum possible score is k - 1 + maxPts
        # If n covers that entire range, probability is 1.
        if n >= k - 1 + maxPts:
            return 1.0

        dp = [0.0] * (n + 1)
        dp[0] = 1.0

        window_sum = 1.0
        answer = 0.0

        for i in range(1, n + 1):

            dp[i] = window_sum / maxPts

            # If i >= k, Alice has stopped.
            if i >= k:
                answer += dp[i]
            else:
                # i < k means Alice can still draw
                window_sum += dp[i]

            # Remove the probability that is now
            # too far away to contribute.
            if i - maxPts >= 0:
                window_sum -= dp[i - maxPts]

        return answer