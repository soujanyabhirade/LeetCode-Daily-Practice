class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        for (int j = 0; j < nums2.size(); j++) {
            int left = 0;
            int right = min(j, (int)nums1.size() - 1);

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums1[mid] <= nums2[j]) {
                    ans = max(ans, j - mid);
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return ans;
    }
};