class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> target(10, 0);

        // Count digits of n
        while (n > 0) {
            target[n % 10]++;
            n /= 10;
        }

        // Check all powers of 2
        for (int i = 0; i < 31; i++) {
            int x = 1 << i;

            vector<int> freq(10, 0);

            while (x > 0) {
                freq[x % 10]++;
                x /= 10;
            }

            if (freq == target)
                return true;
        }

        return false;
    }
};