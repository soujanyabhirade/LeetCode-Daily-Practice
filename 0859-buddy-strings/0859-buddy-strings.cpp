class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        vector<int> diff;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                diff.push_back(i);
            }
        }

        // More than 2 different positions -> impossible
        if (diff.size() > 2)
            return false;

        // Exactly 2 different positions
        if (diff.size() == 2) {
            int i = diff[0];
            int j = diff[1];

            return s[i] == goal[j] && s[j] == goal[i];
        }

        // Strings are already equal.
        // We need at least one duplicate character so that
        // swapping two equal characters changes nothing.
        if (diff.size() == 0) {
            vector<int> freq(26, 0);

            for (char c : s) {
                freq[c - 'a']++;

                if (freq[c - 'a'] >= 2)
                    return true;
            }
        }

        return false;
    }
};