class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;

            for (int bananas : piles) {
                hours += (bananas + mid - 1) / mid;

                // Optional early stopping
                if (hours > h)
                    break;
            }

            if (hours <= h) {
                // mid works, try a smaller speed
                high = mid;
            } else {
                // mid is too slow
                low = mid + 1;
            }
        }

        return low;
    }
};