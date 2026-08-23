class Solution:
    def subarraysWithKDistinct(self, nums, k):

        def atMost(k):
            count = {}
            left = 0
            ans = 0

            for right in range(len(nums)):
                count[nums[right]] = count.get(nums[right], 0) + 1

                # More than k distinct integers
                while len(count) > k:
                    count[nums[left]] -= 1

                    if count[nums[left]] == 0:
                        del count[nums[left]]

                    left += 1

                # All subarrays ending at right are valid
                ans += right - left + 1

            return ans

        return atMost(k) - atMost(k - 1)