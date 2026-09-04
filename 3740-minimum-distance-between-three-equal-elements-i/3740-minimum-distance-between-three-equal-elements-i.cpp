class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] != nums[j])
                    continue;

                for (int k = j + 1; k < n; k++) {
                    if (nums[i] == nums[k]) {
                        int distance = 2 * (k - i);
                        ans = min(ans, distance);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};