class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const long long MOD = 1000000007;

        int n = arr.size();

        sort(arr.begin(), arr.end());

        // dp[i] = number of binary trees with arr[i] as root
        vector<long long> dp(n, 1);

        unordered_map<long long, int> index;

        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                // arr[j] is one factor
                if (arr[i] % arr[j] != 0)
                    continue;

                long long right = arr[i] / arr[j];

                // Check whether the other factor exists
                if (index.count(right)) {

                    int k = index[right];

                    dp[i] = (dp[i] + dp[j] * dp[k]) % MOD;
                }
            }
        }

        long long ans = 0;

        for (long long x : dp) {
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};