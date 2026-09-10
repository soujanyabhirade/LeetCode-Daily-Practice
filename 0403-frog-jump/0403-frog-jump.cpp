class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        // position -> index
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[stones[i]] = i;
        }

        // dp[i] = all jump sizes that can reach stone i
        vector<unordered_set<int>> dp(n);

        // First jump must be 1
        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            for (int lastJump : dp[i]) {

                for (int jump = lastJump - 1;
                     jump <= lastJump + 1;
                     jump++) {

                    if (jump <= 0)
                        continue;

                    int nextPosition = stones[i] + jump;

                    if (nextPosition == stones[n - 1])
                        return true;

                    if (pos.find(nextPosition) != pos.end()) {
                        int nextIndex = pos[nextPosition];
                        dp[nextIndex].insert(jump);
                    }
                }
            }
        }

        return false;
    }
};