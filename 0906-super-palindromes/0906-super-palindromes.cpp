class Solution {
public:
    bool isPalindrome(long long x) {
        string s = to_string(x);
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }

    long long makePalindrome(long long x, bool odd) {
        string s = to_string(x);
        string t = s;

        int start = odd ? (int)s.size() - 2 : (int)s.size() - 1;

        for (int i = start; i >= 0; i--) {
            t += s[i];
        }

        return stoll(t);
    }

    int superpalindromesInRange(string left, string right) {
        long long L = stoll(left);
        long long R = stoll(right);

        int ans = 0;

        // Root <= sqrt(10^18) = 10^9
        // Generate palindromic roots.
        for (long long half = 1; half <= 100000; half++) {

            // Odd-length palindrome
            long long root = makePalindrome(half, true);

            if (root > 1000000000LL)
                break;

            long long square = root * root;

            if (square > R)
                break;

            if (square >= L && isPalindrome(square)) {
                ans++;
            }

            // Even-length palindrome
            root = makePalindrome(half, false);

            if (root > 1000000000LL)
                continue;

            square = root * root;

            if (square >= L && square <= R && isPalindrome(square)) {
                ans++;
            }
        }

        return ans;
    }
};