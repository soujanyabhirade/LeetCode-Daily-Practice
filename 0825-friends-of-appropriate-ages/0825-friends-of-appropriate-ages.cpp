class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);

        // Count how many people have each age
        for (int age : ages) {
            count[age]++;
        }

        int ans = 0;

        // x = age of person sending request
        // y = age of person receiving request
        for (int x = 1; x <= 120; x++) {
            if (count[x] == 0) continue;

            for (int y = 1; y <= 120; y++) {
                if (count[y] == 0) continue;

                // y cannot receive from x if:
                if (y <= 0.5 * x + 7) continue;
                if (y > x) continue;
                if (y > 100 && x < 100) continue;

                // Number of possible x -> y requests
                ans += count[x] * count[y];

                // A person cannot send a request to themselves
                if (x == y) {
                    ans -= count[x];
                }
            }
        }

        return ans;
    }
};