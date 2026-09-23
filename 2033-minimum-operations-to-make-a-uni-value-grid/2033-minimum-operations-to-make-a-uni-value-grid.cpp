class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for (auto& row : grid) {
            for (int val : row) {
                nums.push_back(val);
            }
        }

        // All values must have the same remainder modulo x
        int rem = nums[0] % x;

        for (int val : nums) {
            if (val % x != rem)
                return -1;
        }

        // Median minimizes sum of absolute differences
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];

        long long operations = 0;

        for (int val : nums) {
            operations += abs(val - median) / x;
        }

        return operations;
    }
};