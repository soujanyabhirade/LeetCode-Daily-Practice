class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        
        int n = nums.size();

        sort(nums.begin(), nums.end());

        // power[i] = 2^i % MOD
        vector<long long> power(n);
        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            // Contribution when nums[i] is maximum
            long long asMax = power[i];

            // Contribution when nums[i] is minimum
            long long asMin = power[n - i - 1];

            long long contribution =
                nums[i] * (asMax - asMin);

            ans = (ans + contribution) % MOD;
        }

        // C++ can leave negative remainder
        if (ans < 0)
            ans += MOD;

        return ans;
    }
};