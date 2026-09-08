class Solution {
public:
    long long countCommas(int n) {
        if (n < 1000)
            return 0;

        return n - 999;
    }
};