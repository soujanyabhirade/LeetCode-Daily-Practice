class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int right = 0;
        int left = 0;
        int blank = 0;

        for (char c : moves) {
            if (c == 'R')
                right++;
            else if (c == 'L')
                left++;
            else
                blank++;
        }

        return abs(right - left) + blank;
    }
};