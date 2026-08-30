class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initially, don't change anything
        int ans = nums[n - 1] - nums[0];

        for (int i = 0; i < n - 1; i++) {
            // Left part: +k
            int low = min(nums[0] + k, nums[i + 1] - k);

            // Right part: -k
            int high = max(nums[i] + k, nums[n - 1] - k);

            ans = min(ans, high - low);
        }

        return ans;
    }
};