class Solution(object):
    def summaryRanges(self, nums):
        result = []

        i = 0
        while i < len(nums):
            start = nums[i]

            # Move while numbers are consecutive
            while i + 1 < len(nums) and nums[i + 1] == nums[i] + 1:
                i += 1

            end = nums[i]

            # Add range to result
            if start == end:
                result.append(str(start))
            else:
                result.append(str(start) + "->" + str(end))

            i += 1

        return result