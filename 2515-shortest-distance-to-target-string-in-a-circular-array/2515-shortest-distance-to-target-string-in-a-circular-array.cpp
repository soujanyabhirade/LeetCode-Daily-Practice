class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int diff = abs(i - startIndex);

                int distance = min(diff, n - diff);

                ans = min(ans, distance);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};