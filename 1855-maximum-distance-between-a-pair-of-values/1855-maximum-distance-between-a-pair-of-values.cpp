class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int left = i;
            int right = nums2.size() - 1;
            int best = i;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums1[i] <= nums2[mid]) {
                    best = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            ans = max(ans, best - i);
        }

        return ans;
    }
};