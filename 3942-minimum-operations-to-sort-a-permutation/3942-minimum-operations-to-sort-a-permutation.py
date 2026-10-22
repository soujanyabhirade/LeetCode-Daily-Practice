class Solution:
    def minOperations(self, nums):
        n = len(nums)

        def rotation_cost(arr):
            pos = arr.index(0)

            for i in range(n):
                if arr[(pos + i) % n] != i:
                    return -1

            return pos

        ans = float('inf')

        # Case 1: Rotate the original array
        k = rotation_cost(nums)
        if k != -1:
            ans = min(ans, k, n - k + 2 if k != 0 else 0)

        # Case 2: Reverse and rotate, or rotate and reverse
        k = rotation_cost(nums[::-1])
        if k != -1:
            ans = min(ans, k + 1, n - k + 1)

        return ans if ans != float('inf') else -1