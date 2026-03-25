class Solution:
    def countValidSelections(self, nums):
        result = 0

        for start in range(len(nums)):
            if nums[start] != 0:
                continue
            for direction in [1, -1]:
                if self.simulate(nums[:], start, direction):
                    result += 1

        return result

    def simulate(self, nums, curr, direction):
        n = len(nums)

        while 0 <= curr < n:
            if nums[curr] == 0:
                curr += direction
            else:
                nums[curr] -= 1
                direction = -direction
                curr += direction

        return all(x == 0 for x in nums)