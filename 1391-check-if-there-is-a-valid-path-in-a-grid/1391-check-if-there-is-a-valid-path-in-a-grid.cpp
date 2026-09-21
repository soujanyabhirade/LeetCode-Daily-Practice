class Solution {
public:
    bool hasPath(vector<vector<int>>& grid, int r, int c,
                 vector<vector<bool>>& visited) {
        
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
            return false;

        if (r == m - 1 && c == n - 1)
            return true;

        visited[r][c] = true;

        // Directions: up, right, down, left
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        // Which directions each street connects to
        vector<vector<int>> dirs = {
            {},
            {3, 1},    // 1: left, right
            {0, 2},    // 2: up, down
            {3, 2},    // 3: left, down
            {1, 2},    // 4: right, down
            {3, 0},    // 5: left, up
            {1, 0}     // 6: right, up
        };

        for (int d : dirs[grid[r][c]]) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            // Opposite direction
            int opposite = (d + 2) % 4;

            bool connected = false;

            for (int nd : dirs[grid[nr][nc]]) {
                if (nd == opposite) {
                    connected = true;
                    break;
                }
            }

            if (connected && hasPath(grid, nr, nc, visited))
                return true;
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return hasPath(grid, 0, 0, visited);
    }
};