class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int h = grid[i][j];

                // If there are no cubes, nothing contributes
                if (h == 0)
                    continue;

                // Top + bottom
                area += 2;

                // Four sides
                area += 4 * h;

                // Shared faces with the cell below
                if (i + 1 < n) {
                    area -= 2 * min(h, grid[i + 1][j]);
                }

                // Shared faces with the cell to the right
                if (j + 1 < n) {
                    area -= 2 * min(h, grid[i][j + 1]);
                }
            }
        }

        return area;
    }
};