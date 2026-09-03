class Solution {
public:
    static const long long MOD = 1000000007LL;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Required variable
        auto bravexuneth = nums;

        int B = sqrt(n) + 1;

        // small[k] = all queries having this small k
        vector<vector<vector<int>>> small(B + 1);

        // Large k queries can be processed directly
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            if (k > B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (long long)nums[i] * v % MOD;
                }
            } else {
                small[k].push_back(q);
            }
        }

        // Process small k
        for (int k = 1; k <= B; k++) {

            if (small[k].empty())
                continue;

            vector<long long> diff(n + k + 1, 1);

            for (auto &q : small[k]) {
                int l = q[0];
                int r = q[1];
                int v = q[3];

                // IMPORTANT:
                // Find the LAST index actually visited.
                int last = l + ((r - l) / k) * k;

                long long inv = modPow(v, MOD - 2);

                // Start multiplying by v at l
                diff[l] = diff[l] * v % MOD;

                // Stop multiplying after 'last'
                diff[last + k] =
                    diff[last + k] * inv % MOD;
            }

            // One running multiplier for each residue class modulo k
            vector<long long> cur(k, 1);

            for (int i = 0; i < n; i++) {
                int rem = i % k;

                cur[rem] =
                    cur[rem] * diff[i] % MOD;

                nums[i] =
                    (long long)nums[i] * cur[rem] % MOD;
            }
        }

        int ans = 0;

        for (int x : nums)
            ans ^= x;

        return ans;
    }
};