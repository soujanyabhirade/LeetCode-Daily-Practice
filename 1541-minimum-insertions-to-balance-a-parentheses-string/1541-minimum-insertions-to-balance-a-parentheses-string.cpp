class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // Closing pair must be ))
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    // Insert one ')' to complete the pair
                    ans++;
                }

                if (open > 0) {
                    open--;
                } else {
                    // Insert '(' to match this closing pair
                    ans++;
                }
            }
        }

        // Each remaining '(' needs two ')'
        ans += open * 2;

        return ans;
    }
};