from collections import deque

class Solution:
    def shortestSubarray(self, nums, k):
        n = len(nums)

        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        dq = deque()
        ans = n + 1

        for i in range(n + 1):

            # Try to find a valid subarray
            while dq and prefix[i] - prefix[dq[0]] >= k:
                ans = min(ans, i - dq.popleft())

            # Remove useless candidates
            while dq and prefix[i] <= prefix[dq[-1]]:
                dq.pop()

            dq.append(i)

        return ans if ans <= n else -1