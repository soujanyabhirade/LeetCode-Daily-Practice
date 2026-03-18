class Solution:
    def removeDuplicates(self, nums):
        k = 1  # first element is always unique

        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:  # found a new unique element
                nums[k] = nums[i]        # place it at position k
                k += 1

        return k