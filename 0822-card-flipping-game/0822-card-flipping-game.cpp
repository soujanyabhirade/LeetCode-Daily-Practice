class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> bad;

        int n = fronts.size();

        // Numbers that appear on both sides
        // of the same card can never be good.
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                bad.insert(fronts[i]);
            }
        }

        int ans = INT_MAX;

        // Check all possible numbers
        for (int i = 0; i < n; i++) {

            if (!bad.count(fronts[i])) {
                ans = min(ans, fronts[i]);
            }

            if (!bad.count(backs[i])) {
                ans = min(ans, backs[i]);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};