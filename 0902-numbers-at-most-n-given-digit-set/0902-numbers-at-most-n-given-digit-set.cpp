class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int len = s.length();
        int k = digits.size();

        int ans = 0;

        // Count numbers with fewer digits than n
        for (int l = 1; l < len; l++) {
            ans += pow(k, l);
        }

        // Count numbers with the same number of digits
        for (int i = 0; i < len; i++) {

            int current = s[i] - '0';

            // Count available digits smaller than current
            int smaller = 0;

            for (string d : digits) {
                if (d[0] - '0' < current)
                    smaller++;
            }

            // Choose a smaller digit here.
            // Remaining positions can use any digit.
            ans += smaller * pow(k, len - i - 1);

            // If current digit is not available,
            // we cannot continue matching n.
            bool exists = false;

            for (string d : digits) {
                if (d[0] - '0' == current) {
                    exists = true;
                    break;
                }
            }

            if (!exists)
                return ans;
        }

        // n itself can be generated
        return ans + 1;
    }
};