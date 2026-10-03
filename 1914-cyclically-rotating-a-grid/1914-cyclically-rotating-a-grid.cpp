class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> values;

            int top = layer;
            int left = layer;
            int bottom = m - 1 - layer;
            int right = n - 1 - layer;

            // Top row
            for (int j = left; j <= right; j++)
                values.push_back(grid[top][j]);

            // Right column
            for (int i = top + 1; i <= bottom; i++)
                values.push_back(grid[i][right]);

            // Bottom row
            for (int j = right - 1; j >= left; j--)
                values.push_back(grid[bottom][j]);

            // Left column
            for (int i = bottom - 1; i > top; i--)
                values.push_back(grid[i][left]);

            int len = values.size();
            int shift = k % len;

            // Counter-clockwise rotation
            rotate(values.begin(), values.begin() + shift, values.end());

            int idx = 0;

            // Put back: top row
            for (int j = left; j <= right; j++)
                grid[top][j] = values[idx++];

            // Right column
            for (int i = top + 1; i <= bottom; i++)
                grid[i][right] = values[idx++];

            // Bottom row
            for (int j = right - 1; j >= left; j--)
                grid[bottom][j] = values[idx++];

            // Left column
            for (int i = bottom - 1; i > top; i--)
                grid[i][left] = values[idx++];
        }

        return grid;
    }
};