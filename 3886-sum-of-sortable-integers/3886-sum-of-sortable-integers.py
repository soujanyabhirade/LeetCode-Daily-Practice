class Solution:
    def sortableIntegers(self, nums):
        n = len(nums)
        ans = 0
        globally_sorted = nums == sorted(nums)

        for k in range(1, n + 1):
            if n % k != 0:
                continue

            if k == 1:
                if globally_sorted:
                    ans += 1
                continue

            valid = True
            prev_max = float('-inf')

            for start in range(0, n, k):
                block = nums[start:start + k]

                # A block can be rotated into sorted order
                drops = 0
                for i in range(k):
                    if block[i] > block[(i + 1) % k]:
                        drops += 1
                        if drops > 1:
                            valid = False
                            break

                if not valid:
                    break

                # The sorted values of each block must fit
                # in global non-decreasing order.
                block_min = min(block)
                block_max = max(block)

                if block_min < prev_max:
                    valid = False
                    break

                prev_max = block_max

            if valid:
                ans += k

        return ans