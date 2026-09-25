class Solution {
public:
    bool isGood(int x) {
        bool changed = false;

        while (x > 0) {
            int d = x % 10;

            // Invalid digits
            if (d == 3 || d == 4 || d == 7)
                return false;

            // These digits change after rotation
            if (d == 2 || d == 5 || d == 6 || d == 9)
                changed = true;

            x /= 10;
        }

        return changed;
    }

    int rotatedDigits(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (isGood(i))
                ans++;
        }

        return ans;
    }
};