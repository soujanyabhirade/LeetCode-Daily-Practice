class Solution:
    def canPartitionGrid(self, grid):
        total = sum(sum(row) for row in grid)

        # Check horizontal cuts
        prefix = 0
        for i in range(len(grid) - 1):
            prefix += sum(grid[i])
            if prefix * 2 == total:
                return True

        # Check vertical cuts
        prefix = 0
        for j in range(len(grid[0]) - 1):
            prefix += sum(grid[i][j] for i in range(len(grid)))
            if prefix * 2 == total:
                return True

        return False
        