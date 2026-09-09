class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Store reserved seats as a bitmask for each row
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << col);
        }

        // Initially every row can accommodate 2 groups
        long long ans = 2LL * n;

        for (auto &[row, mask] : rows) {

            // This row was initially counted as 2 groups.
            // Check which blocks are available.

            // Seats 2,3,4,5
            bool left = (mask & (1 << 2)) == 0 &&
                        (mask & (1 << 3)) == 0 &&
                        (mask & (1 << 4)) == 0 &&
                        (mask & (1 << 5)) == 0;

            // Seats 6,7,8,9
            bool right = (mask & (1 << 6)) == 0 &&
                         (mask & (1 << 7)) == 0 &&
                         (mask & (1 << 8)) == 0 &&
                         (mask & (1 << 9)) == 0;

            // Seats 4,5,6,7
            bool middle = (mask & (1 << 4)) == 0 &&
                          (mask & (1 << 5)) == 0 &&
                          (mask & (1 << 6)) == 0 &&
                          (mask & (1 << 7)) == 0;

            // Remove the default 2 groups for this row
            ans -= 2;

            if (left && right) {
                // Can fit two groups
                ans += 2;
            }
            else if (left || right || middle) {
                // Can fit one group
                ans += 1;
            }
        }

        return ans;
    }
};