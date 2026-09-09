class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // 4 to 6 digits -> 1 comma
        if (n >= 1000) {
            ans += min(n, 999999LL) - 999;
        }

        // 7 to 9 digits -> 2 commas
        if (n >= 1000000) {
            ans += (min(n, 999999999LL) - 999999LL) * 2;
        }

        // 10 to 12 digits -> 3 commas
        if (n >= 1000000000LL) {
            ans += (min(n, 999999999999LL) - 999999999LL) * 3;
        }

        // 13 to 15 digits -> 4 commas
        if (n >= 1000000000000LL) {
            ans += (min(n, 999999999999999LL) - 999999999999LL) * 4;
        }

        // 16 digits -> 5 commas
        if (n >= 1000000000000000LL) {
            ans += (n - 999999999999999LL) * 5;
        }

        return ans;
    }
};