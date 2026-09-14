class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, long long> count;
        unordered_map<int, long long> sum;

        // Left side
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            ans[i] += (long long)i * count[x] - sum[x];

            count[x]++;
            sum[x] += i;
        }

        count.clear();
        sum.clear();

        // Right side
        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];

            ans[i] += sum[x] - (long long)i * count[x];

            count[x]++;
            sum[x] += i;
        }

        return ans;
    }
};