class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        // Center of a 3x3 magic square must be 5
        if (grid[r + 1][c + 1] != 5)
            return false;

        // Check that numbers are distinct and between 1 and 9
        bool seen[10] = {};

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int x = grid[i][j];

                if (x < 1 || x > 9 || seen[x])
                    return false;

                seen[x] = true;
            }
        }

        // Every row, column and diagonal must sum to 15
        for (int i = 0; i < 3; i++) {
            if (grid[r + i][c] +
                grid[r + i][c + 1] +
                grid[r + i][c + 2] != 15)
                return false;

            if (grid[r][c + i] +
                grid[r + 1][c + i] +
                grid[r + 2][c + i] != 15)
                return false;
        }

        // Diagonals
        if (grid[r][c] +
            grid[r + 1][c + 1] +
            grid[r + 2][c + 2] != 15)
            return false;

        if (grid[r][c + 2] +
            grid[r + 1][c + 1] +
            grid[r + 2][c] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int ans = 0;

        // Try every possible top-left corner of a 3x3 subgrid
        for (int r = 0; r + 2 < rows; r++) {
            for (int c = 0; c + 2 < cols; c++) {
                if (isMagic(grid, r, c))
                    ans++;
            }
        }

        return ans;
    }
};