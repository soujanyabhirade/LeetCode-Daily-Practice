class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int nthMagicalNumber(int n, int a, int b) {
        const long long MOD = 1000000007;

        long long g = gcd(a, b);

        // LCM(a, b)
        long long lcm = (1LL * a / g) * b;

        // Binary search range
        long long low = 1;
        long long high = 1LL * n * min(a, b);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            // Number of magical numbers <= mid
            long long count =
                mid / a +
                mid / b -
                mid / lcm;

            if (count >= n) {
                // mid can be the answer
                high = mid;
            } else {
                // Need a larger number
                low = mid + 1;
            }
        }

        return low % MOD;
    }
};