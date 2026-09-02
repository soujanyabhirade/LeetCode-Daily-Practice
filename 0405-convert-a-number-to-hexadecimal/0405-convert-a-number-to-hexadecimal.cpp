class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";

        string hex = "0123456789abcdef";
        string result = "";

        unsigned int n = num;

        while (n > 0) {
            int digit = n & 15;   // Get last 4 bits
            result += hex[digit];
            n >>= 4;              // Remove last 4 bits
        }

        reverse(result.begin(), result.end());

        return result;
    }
};