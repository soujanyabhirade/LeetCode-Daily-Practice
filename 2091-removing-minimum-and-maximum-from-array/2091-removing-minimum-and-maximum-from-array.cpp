class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find positions of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // Option 1: remove both from the front
        int fromFront = right + 1;

        // Option 2: remove both from the back
        int fromBack = n - left;

        // Option 3: remove left from front, right from back
        int bothSides = (left + 1) + (n - right);

        return min({fromFront, fromBack, bothSides});
    }
};