class Solution:
    def findKthLargest(self, nums, k):
        count = [0] * 20001

        for num in nums:
            count[num + 10000] += 1

        for i in range(20000, -1, -1):
            k -= count[i]

            if k <= 0:
                return i - 10000