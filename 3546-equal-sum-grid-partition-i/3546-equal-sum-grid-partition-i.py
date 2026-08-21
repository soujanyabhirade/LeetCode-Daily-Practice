class Solution:
    def canPartitionGrid(self, grid):
        m = len(grid)
        n = len(grid[0])

        total = sum(map(sum, grid))

        # Horizontal cuts
        current = 0

        for i in range(m - 1):
            current += sum(grid[i])

            if current * 2 == total:
                return True

        # Vertical cuts
        current = 0

        for j in range(n - 1):
            for i in range(m):
                current += grid[i][j]

            if current * 2 == total:
                return True

        return False