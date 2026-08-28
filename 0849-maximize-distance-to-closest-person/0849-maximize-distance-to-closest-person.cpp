
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int ans = 0;

        // Find first occupied seat
        int first = 0;
        while (seats[first] == 0) {
            first++;
        }

        // Empty seats at the beginning
        ans = first;

        // Check gaps between occupied seats
        int prev = first;

        for (int i = first + 1; i < n; i++) {
            if (seats[i] == 1) {
                // Distance to the closest person in the middle
                ans = max(ans, (i - prev) / 2);

                prev = i;
            }
        }

        // Empty seats at the end
        ans = max(ans, n - 1 - prev);

        return ans;
    }
};

