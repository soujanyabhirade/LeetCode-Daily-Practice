class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());

        // Try making everything even
        bool possibleEven = true;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                // Already even
                continue;
            }

            // Need a smaller odd number to subtract:
            // odd - odd = even
            bool found = false;

            for (int j = 0; j < i; j++) {
                if (nums1[j] % 2 == 1) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                possibleEven = false;
                break;
            }
        }

        // Try making everything odd
        bool possibleOdd = true;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 1) {
                // Already odd
                continue;
            }

            // Need a smaller even number:
            // even - even = even, so this does NOT change parity.
            // Therefore an even number cannot become odd by
            // subtracting an even number.
            //
            // It can become odd only by subtracting an odd number.
            bool found = false;

            for (int j = 0; j < i; j++) {
                if (nums1[j] % 2 == 1) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                possibleOdd = false;
                break;
            }
        }

        return possibleEven || possibleOdd;
    }
};