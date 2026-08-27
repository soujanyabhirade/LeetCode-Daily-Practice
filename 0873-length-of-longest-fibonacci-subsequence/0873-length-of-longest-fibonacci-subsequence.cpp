class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        // value -> index
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        // dp[i][j] = length of Fibonacci-like subsequence
        // ending with arr[i], arr[j]
        vector<vector<int>> dp(n, vector<int>(n, 2));

        int ans = 0;

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {

                // We need arr[k] + arr[i] = arr[j]
                int prev = arr[j] - arr[i];

                if (mp.count(prev)) {
                    int k = mp[prev];

                    // k must come before i
                    if (k < i) {
                        dp[i][j] = dp[k][i] + 1;
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }

        return ans >= 3 ? ans : 0;
    }
};