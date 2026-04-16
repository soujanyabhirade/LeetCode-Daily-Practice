from collections import deque

class Solution:
    def maxSlidingWindow(self, nums, k):
        dq = deque()  # stores indices, decreasing order of values
        result = []

        for i, num in enumerate(nums):
            # Remove indices outside the window
            while dq and dq[0] < i - k + 1:
                dq.popleft()

            # Remove indices whose values are smaller than current
            # (they can never be the max while current element is in window)
            while dq and nums[dq[-1]] <= num:
                dq.pop()

            dq.append(i)

            # Start adding results once first window is complete
            if i >= k - 1:
                result.append(nums[dq[0]])

        return result