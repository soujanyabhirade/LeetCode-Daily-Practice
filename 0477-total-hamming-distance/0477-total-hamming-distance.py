class Solution:
    def totalHammingDistance(self, nums):
        n = len(nums)
        ans = 0

        # nums[i] <= 10^9, so 31 bits are enough
        for bit in range(31):
            ones = 0

            for num in nums:
                if num & (1 << bit):
                    ones += 1

            zeros = n - ones

            # Every 1 pairs with every 0
            ans += ones * zeros

        return ans