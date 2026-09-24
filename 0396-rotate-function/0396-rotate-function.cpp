class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        long long f = 0;

        // Calculate sum and F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += 1LL * i * nums[i];
        }

        long long ans = f;

        // Calculate F(1), F(2), ...
        for (int k = 1; k < n; k++) {
            f = f + sum - 1LL * n * nums[n - k];
            ans = max(ans, f);
        }

        return (int)ans;
    }
};