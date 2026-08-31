class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Mark numbers that exist
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);

            nums[x - 1] = -abs(nums[x - 1]);
        }

        // Positive positions represent missing numbers
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};