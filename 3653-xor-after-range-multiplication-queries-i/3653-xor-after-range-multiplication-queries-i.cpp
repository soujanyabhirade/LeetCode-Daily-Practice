class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            for (int i = l; i <= r; i += k) {
                nums[i] = (nums[i] * 1LL * v) % MOD;
            }
        }

        int ans = 0;

        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};