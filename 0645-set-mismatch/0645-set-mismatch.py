class Solution:
    def findErrorNums(self, nums):
        n = len(nums)

        count = [0] * (n + 1)

        for num in nums:
            count[num] += 1

        duplicate = 0
        missing = 0

        for i in range(1, n + 1):
            if count[i] == 2:
                duplicate = i
            elif count[i] == 0:
                missing = i

        return [duplicate, missing]