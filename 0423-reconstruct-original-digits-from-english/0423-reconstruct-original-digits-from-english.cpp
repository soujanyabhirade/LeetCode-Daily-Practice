class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0);

        // Count every character
        for (char c : s) {
            count[c - 'a']++;
        }

        vector<int> digit(10, 0);

        // Unique characters
        digit[0] = count['z' - 'a'];  // zero
        digit[2] = count['w' - 'a'];  // two
        digit[4] = count['u' - 'a'];  // four
        digit[6] = count['x' - 'a'];  // six
        digit[8] = count['g' - 'a'];  // eight

        // Remove the letters already used
        digit[3] = count['h' - 'a'] - digit[8];              // three
        digit[5] = count['f' - 'a'] - digit[4];              // five
        digit[7] = count['s' - 'a'] - digit[6];              // seven

        digit[1] = count['o' - 'a'] - digit[0]
                                  - digit[2]
                                  - digit[4];                // one

        digit[9] = count['i' - 'a'] - digit[5]
                                  - digit[6]
                                  - digit[8];                // nine

        // Build answer in ascending order
        string ans;

        for (int i = 0; i <= 9; i++) {
            while (digit[i] > 0) {
                ans += char('0' + i);
                digit[i]--;
            }
        }

        return ans;
    }
};