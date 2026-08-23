class Solution:
    def numSubarraysWithSum(self, nums, goal):
        count = {0: 1}
        prefix = 0
        ans = 0

        for num in nums:
            prefix += num

            # Number of previous prefix sums that
            # make the current subarray sum = goal
            ans += count.get(prefix - goal, 0)

            count[prefix] = count.get(prefix, 0) + 1

        return ans