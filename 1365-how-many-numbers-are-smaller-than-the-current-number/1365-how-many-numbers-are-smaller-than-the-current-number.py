class Solution:
    def smallerNumbersThanCurrent(self, nums):
        result = []

        for num in nums:
            count = 0

            for x in nums:
                if x < num:
                    count += 1

            result.append(count)

        return result