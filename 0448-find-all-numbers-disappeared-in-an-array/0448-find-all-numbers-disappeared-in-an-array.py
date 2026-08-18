class Solution:
    def findDisappearedNumbers(self, nums):
        n = len(nums)

        for num in nums:
            index = abs(num) - 1
            nums[index] = -abs(nums[index])

        result = []

        for i in range(n):
            if nums[i] > 0:
                result.append(i + 1)

        return result