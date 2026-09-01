class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void backtrack(string &s, int start, vector<string>& current) {

        // We have used the entire string
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        // Try every possible substring
        for (int end = start; end < s.length(); end++) {

            // Only choose palindrome substrings
            if (isPalindrome(s, start, end)) {

                // Choose
                current.push_back(s.substr(start, end - start + 1));

                // Explore
                backtrack(s, end + 1, current);

                // Undo
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> current;

        backtrack(s, 0, current);

        return result;
    }
};