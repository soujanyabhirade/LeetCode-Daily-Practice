class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;
        for (int num : nums)
            total += num;

        long long target = total - x;

        // If target < 0, impossible
        if (target < 0)
            return -1;

        // target == 0 means remove the entire array
        if (target == 0)
            return n;

        int left = 0;
        long long sum = 0;
        int longest = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                longest = max(longest, right - left + 1);
            }
        }

        if (longest == -1)
            return -1;

        return n - longest;
    }
};