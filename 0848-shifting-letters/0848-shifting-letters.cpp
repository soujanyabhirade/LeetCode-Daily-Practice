
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long totalShift = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            totalShift = (totalShift + shifts[i]) % 26;

            int current = s[i] - 'a';
            current = (current + totalShift) % 26;

            s[i] = 'a' + current;
        }

        return s;
    }
};

