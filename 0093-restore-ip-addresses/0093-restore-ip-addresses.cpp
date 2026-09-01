class Solution {
public:
    vector<string> result;

    bool isValid(string s) {
        // Leading zero
        if (s.length() > 1 && s[0] == '0')
            return false;

        int num = stoi(s);

        return num >= 0 && num <= 255;
    }

    void backtrack(string &s, int index, int parts, string current) {

        // We have exactly 4 parts
        if (parts == 4) {
            // All digits must be used
            if (index == s.length()) {
                current.pop_back(); // remove last '.'
                result.push_back(current);
            }
            return;
        }

        // Try taking 1, 2, or 3 digits
        for (int len = 1; len <= 3; len++) {

            if (index + len > s.length())
                break;

            string part = s.substr(index, len);

            if (!isValid(part))
                continue;

            backtrack(
                s,
                index + len,
                parts + 1,
                current + part + "."
            );
        }
    }

    vector<string> restoreIpAddresses(string s) {

        result.clear();

        // An IP address has exactly 4 parts,
        // each part has at most 3 digits.
        if (s.length() < 4 || s.length() > 12)
            return result;

        backtrack(s, 0, 0, "");

        return result;
    }
};