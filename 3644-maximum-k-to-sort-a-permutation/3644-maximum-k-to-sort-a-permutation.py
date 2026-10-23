class Solution:
    def sortPermutation(self, nums):
        n = len(nums)
        ans = (1 << 31) - 1
        found = False

        for i in range(n):
            if nums[i] != i:
                ans &= nums[i]
                found = True

        return ans if found else 0