class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        vector<pair<int, int>> litter;

        // Find S and all L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // Map each litter position to a bit
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        int fullMask = (1 << k) - 1;

        /*
            State:
            (row, col, energy, mask)

            Instead of storing every possible energy in visited,
            store the maximum energy reached for:
            (row, col, mask)

            If we reach the same state with less/equal energy,
            that state is useless.
        */

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        struct State {
            int r, c, e, mask, dist;
        };

        queue<State> q;

        best[sr][sc][0] = energy;
        q.push({sr, sc, energy, 0, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            int e = cur.e;
            int mask = cur.mask;
            int dist = cur.dist;

            if (mask == fullMask)
                return dist;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                // Moving costs 1 energy
                int ne = e - 1;

                if (ne < 0)
                    continue;

                int nmask = mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {
                    nmask |= (1 << id[nr][nc]);
                }

                // Reset energy at R
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                /*
                    If we have already reached this
                    position + mask with MORE energy,
                    this new state is useless.
                */
                if (ne <= best[nr][nc][nmask])
                    continue;

                best[nr][nc][nmask] = ne;

                q.push({
                    nr,
                    nc,
                    ne,
                    nmask,
                    dist + 1
                });
            }
        }

        return -1;
    }
};