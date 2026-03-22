class Solution:
    def subsets(self, nums):
        result = []

        def backtrack(start, current):
            # Add every state (not just leaves) to result
            result.append(current[:])

            for i in range(start, len(nums)):
                current.append(nums[i])
                backtrack(i + 1, current)
                current.pop()

        backtrack(0, [])
        return result
        