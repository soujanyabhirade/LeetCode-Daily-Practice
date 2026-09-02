class Solution {
public:
    vector<int> nums;

    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int result = -1;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                count++;

                // Choose this index with probability 1/count
                if (rand() % count == 0) {
                    result = i;
                }
            }
        }

        return result;
    }
};