class Solution:
    def digitSum(self, x):
        total = 0
        while x > 0:
            total += x % 10
            x //= 10
        return total

    def minSwaps(self, nums):
        n = len(nums)

        sorted_nums = sorted(nums, key=lambda x: (self.digitSum(x), x))

        target_index = {value: i for i, value in enumerate(sorted_nums)}

        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i] or target_index[nums[i]] == i:
                continue

            cycle_size = 0
            j = i

            while not visited[j]:
                visited[j] = True
                j = target_index[nums[j]]
                cycle_size += 1

            swaps += cycle_size - 1

        return swaps