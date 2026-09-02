class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1;
        long long count = 9;
        long long start = 1;

        // Find the range containing the nth digit
        while (n > digits * count) {
            n -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }

        // Find the actual number
        long long num = start + (n - 1) / digits;

        // Find the digit inside that number
        int index = (n - 1) % digits;

        string s = to_string(num);

        return s[index] - '0';
    }
};