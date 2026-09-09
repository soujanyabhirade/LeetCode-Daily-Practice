class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int left = 0;
        int right = tokens.size() - 1;
        int score = 0;
        int ans = 0;

        while (left <= right) {

            // Play the smallest token face-up
            if (power >= tokens[left]) {
                power -= tokens[left];
                score++;
                ans = max(ans, score);
                left++;
            }

            // If we cannot play face-up, trade score for power
            else if (score > 0 && left < right) {
                power += tokens[right];
                score--;
                right--;
            }

            else {
                break;
            }
        }

        return ans;
    }
};