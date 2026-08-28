
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        unordered_set<long long> blocked;

        // Store obstacles
        for (auto &obs : obstacles) {
            long long x = obs[0];
            long long y = obs[1];

            long long key = (x << 32) ^ (y & 0xffffffffLL);
            blocked.insert(key);
        }

        // 0 = North
        // 1 = East
        // 2 = South
        // 3 = West
        int dir = 0;

        int x = 0;
        int y = 0;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int ans = 0;

        for (int command : commands) {

            // Turn left
            if (command == -2) {
                dir = (dir + 3) % 4;
            }

            // Turn right
            else if (command == -1) {
                dir = (dir + 1) % 4;
            }

            // Move forward
            else {
                for (int step = 0; step < command; step++) {

                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    long long key =
                        ((long long)nx << 32) ^ (ny & 0xffffffffLL);

                    // Obstacle ahead
                    if (blocked.count(key)) {
                        break;
                    }

                    // Move
                    x = nx;
                    y = ny;

                    // Update maximum distance
                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};

