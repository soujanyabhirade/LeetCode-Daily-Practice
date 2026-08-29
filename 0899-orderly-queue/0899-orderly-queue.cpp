class Solution {
public:
    string orderlyQueue(string s, int k) {

        // Case 1: Only rotations are possible
        if (k == 1) {
            string ans = s;
            int n = s.length();

            for (int i = 1; i < n; i++) {
                string rotated = s.substr(i) + s.substr(0, i);
                ans = min(ans, rotated);
            }

            return ans;
        }

        // Case 2: We can arrange characters arbitrarily
        sort(s.begin(), s.end());
        return s;
    }
};