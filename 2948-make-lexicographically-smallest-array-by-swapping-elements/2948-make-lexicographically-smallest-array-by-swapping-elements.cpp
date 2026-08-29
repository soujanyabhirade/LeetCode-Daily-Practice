
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        // Sort by value
        sort(a.begin(), a.end());

        int start = 0;

        while (start < n) {
            int end = start;

            // Find the complete connected group
            while (end + 1 < n &&
                   a[end + 1].first - a[end].first <= limit) {
                end++;
            }

            // Get original indices of this group
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(a[i].second);
            }

            // Original indices must be sorted
            sort(indices.begin(), indices.end());

            // Values are already sorted because a is sorted
            for (int i = 0; i < indices.size(); i++) {
                nums[indices[i]] = a[start + i].first;
            }

            start = end + 1;
        }

        return nums;
    }
};

