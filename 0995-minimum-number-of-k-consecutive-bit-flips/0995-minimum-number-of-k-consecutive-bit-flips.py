class Solution:
    def minKBitFlips(self, nums, k):
        n = len(nums)

        # flip[i] = 1 means a flip starts at index i
        flip = [0] * n

        current_flips = 0
        ans = 0

        for i in range(n):

            # Remove the effect of the flip that started k positions ago
            if i >= k:
                current_flips -= flip[i - k]

            # Effective value of nums[i]
            if (nums[i] + current_flips) % 2 == 0:

                # We have a 0, so we must flip here
                if i + k > n:
                    return -1

                flip[i] = 1
                current_flips += 1
                ans += 1

        return ans