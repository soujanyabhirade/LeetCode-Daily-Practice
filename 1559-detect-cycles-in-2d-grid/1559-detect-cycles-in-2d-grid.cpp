class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& grid,
             vector<vector<bool>>& visited,
             int r, int c,
             int pr, int pc) {
        
        visited[r][c] = true;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            // Outside grid
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            // Different character
            if (grid[nr][nc] != grid[r][c])
                continue;

            // Don't immediately go back to parent
            if (nr == pr && nc == pc)
                continue;

            // Already visited -> cycle found
            if (visited[nr][nc])
                return true;

            if (dfs(grid, visited, nr, nc, r, c))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1))
                        return true;
                }
            }
        }

        return false;
    }
};